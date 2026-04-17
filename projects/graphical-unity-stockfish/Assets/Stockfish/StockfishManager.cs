using System;
using System.Diagnostics;
using System.IO;
using UnityEngine;

public class StockfishManager : MonoBehaviour
{
    private const string RelativeExecutablePath = "stockfish_15.1_win_x64_popcnt/stockfish-windows-2022-x86-64-modern.exe";

    private Process stockfishProcess;
    private StreamWriter stockfishInput;
    private StreamReader stockfishOutput;
    private static StockfishManager instance;
    private string lastBestMove = string.Empty;

    public static StockfishManager Instance
    {
        get { return instance; }
    }

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(this.gameObject);
            return;
        }

        instance = this;
        DontDestroyOnLoad(this.gameObject);
    }

    private void Start()
    {
        string stockfishPath = Path.GetFullPath(Path.Combine(Application.dataPath, "..", RelativeExecutablePath));

        if (!File.Exists(stockfishPath))
        {
            Debug.LogError($"Stockfish introuvable : {stockfishPath}");
            enabled = false;
            return;
        }

        try
        {
            stockfishProcess = new Process();
            stockfishProcess.StartInfo.FileName = stockfishPath;
            stockfishProcess.StartInfo.WorkingDirectory = Path.GetDirectoryName(stockfishPath);
            stockfishProcess.StartInfo.UseShellExecute = false;
            stockfishProcess.StartInfo.RedirectStandardInput = true;
            stockfishProcess.StartInfo.RedirectStandardOutput = true;
            stockfishProcess.StartInfo.RedirectStandardError = true;
            stockfishProcess.StartInfo.CreateNoWindow = true;
            stockfishProcess.Start();

            stockfishInput = stockfishProcess.StandardInput;
            stockfishOutput = stockfishProcess.StandardOutput;

            SendCommand("uci");
            WaitForToken("uciok");
            SendCommand("isready");
            WaitForToken("readyok");
        }
        catch (Exception ex)
        {
            Debug.LogError($"Impossible de démarrer Stockfish : {ex.Message}");
            enabled = false;
        }
    }

    public void MakeAIMove()
    {
        if (stockfishProcess == null || stockfishProcess.HasExited || BoardManager.Instance == null)
            return;

        string moveHistory = BoardManager.Instance.GetUciMoveHistory();
        if (string.IsNullOrWhiteSpace(moveHistory))
            SendCommand("position startpos");
        else
            SendCommand($"position startpos moves {moveHistory}");

        SendCommand("go movetime 500");
        lastBestMove = ReadBestMove();

        if (!string.IsNullOrEmpty(lastBestMove))
            BoardManager.Instance.ApplyUciMove(lastBestMove);
    }

    private void OnDestroy()
    {
        try
        {
            if (stockfishInput != null)
            {
                stockfishInput.WriteLine("quit");
                stockfishInput.Flush();
            }
        }
        catch
        {
            // Ignore shutdown errors.
        }

        if (stockfishProcess != null && !stockfishProcess.HasExited)
        {
            stockfishProcess.Kill();
            stockfishProcess.WaitForExit(1000);
        }

        stockfishInput?.Close();
        stockfishOutput?.Close();
        stockfishProcess?.Close();
    }

    private void SendCommand(string command)
    {
        if (stockfishInput == null)
            return;

        stockfishInput.WriteLine(command);
        stockfishInput.Flush();
    }

    private void WaitForToken(string token)
    {
        if (stockfishOutput == null)
            return;

        while (true)
        {
            string line = stockfishOutput.ReadLine();
            if (line == null || line.Contains(token))
                return;
        }
    }

    private string ReadBestMove()
    {
        if (stockfishOutput == null)
            return string.Empty;

        while (true)
        {
            string line = stockfishOutput.ReadLine();
            if (line == null)
                return string.Empty;

            if (line.StartsWith("bestmove", StringComparison.OrdinalIgnoreCase))
            {
                string[] parts = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length >= 2 && parts[1] != "(none)")
                    return parts[1];

                return string.Empty;
            }
        }
    }

    public string GetResponse()
    {
        return lastBestMove;
    }
}