using System.Collections;
using UnityEngine;

public class Rook : Chessman
{
    public override void MakeAIMove()
    {
        // Demander à Stockfish de générer le prochain mouvement pour le roi
        StockfishManager.Instance.MakeAIMove();
        string response = StockfishManager.Instance.GetResponse();

        // Interpréter la réponse et appliquer le mouvement dans votre logique de jeu
    }
    public override bool[,] PossibleMoves()
    {
        bool[,] r = new bool[8, 8];

        int i;

        // Right
        i = CurrentX;
        while (true)
        {
            i++;
            if (i >= 8) break;

            if (Move(i, CurrentY, ref r)) break;
        }

        // Left
        i = CurrentX;
        while (true)
        {
            i--;
            if (i < 0) break;

            if (Move(i, CurrentY, ref r)) break;
        }

        // Up
        i = CurrentY;
        while (true)
        {
            i++;
            if (i >= 8) break;

            if (Move(CurrentX, i, ref r)) break;
        }

        // Down
        i = CurrentY;
        while (true)
        {
            i--;
            if (i < 0) break;

            if (Move(CurrentX, i, ref r)) break;

        }

        return r;
    }



}
