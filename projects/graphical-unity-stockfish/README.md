# 3D Chess with Stockfish

Version Unity 3D du projet d'échecs avec intégration d'un moteur Stockfish.

## Fonctionnalités

- plateau 3D,
- déplacement visuel des pièces,
- intégration du moteur Stockfish via UCI,
- base de travail pour une IA plus avancée.

## Structure

- `Assets/le code/` : logique du jeu,
- `Assets/Stockfish/` : wrapper du moteur,
- `stockfish_15.1_win_x64_popcnt/` : exécutable Stockfish attendu par le script.

## Lancement

1. Ouvrir le dossier dans Unity.
2. Vérifier que l'exécutable Stockfish est bien présent dans `stockfish_15.1_win_x64_popcnt/`.
3. Lancer la scène principale.

## Remarques

- le chemin du moteur est désormais calculé de manière relative,
- le projet reste orienté démonstration académique,
- l'amélioration principale concerne encore la synchronisation complète entre l'état du plateau et le moteur.
