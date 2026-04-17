using System.Collections;
using UnityEngine;

public class King : Chessman
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

        Move(CurrentX + 1, CurrentY, ref r); // up
        Move(CurrentX - 1, CurrentY, ref r); // down
        Move(CurrentX, CurrentY - 1, ref r); // left
        Move(CurrentX, CurrentY + 1, ref r); // right
        Move(CurrentX + 1, CurrentY - 1, ref r); // up left
        Move(CurrentX - 1, CurrentY - 1, ref r); // down left
        Move(CurrentX + 1, CurrentY + 1, ref r); // up right
        Move(CurrentX - 1, CurrentY + 1, ref r); // down right

        return r;
    }



}
