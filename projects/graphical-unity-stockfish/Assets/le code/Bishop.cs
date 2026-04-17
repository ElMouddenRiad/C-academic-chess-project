using System.Collections;
using UnityEngine;

public class Bishop : Chessman
{
    public override void MakeAIMove()
    {
        // Demander à Stockfish de générer le prochain mouvement pour le fou
        StockfishManager.Instance.MakeAIMove();
        string response = StockfishManager.Instance.GetResponse();

        // Interpréter la réponse et appliquer le mouvement dans votre logique de jeu
    }
    public override bool[,] PossibleMoves()
    {
        bool[,] r = new bool[8, 8];

        int i, j;

        // Top left
        i = CurrentX;
        j = CurrentY;
        while (true)
        {
            i--;
            j++;
            if (i < 0 || j >= 8) break;

            if (Move(i, j, ref r)) break;
        }

        // Top right
        i = CurrentX;
        j = CurrentY;
        while (true)
        {
            i++;
            j++;
            if (i >= 8 || j >= 8) break;

            if (Move(i, j, ref r)) break;
        }

        // Down left
        i = CurrentX;
        j = CurrentY;
        while (true)
        {
            i--;
            j--;
            if (i < 0 || j < 0) break;

            if (Move(i, j, ref r)) break;
        }

        // Down right
        i = CurrentX;
        j = CurrentY;
        while (true)
        {
            i++;
            j--;
            if (i >= 8 || j < 0) break;

            if (Move(i, j, ref r)) break;
        }


        return r;
    }

}


