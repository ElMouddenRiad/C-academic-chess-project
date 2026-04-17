# Console Chess (C++)

Version console du projet académique d'échecs.

## Description

Ce sous-projet implémente une partie d'échecs jouable dans le terminal avec une logique métier en C++ : plateau, déplacements, tours, coups spéciaux et fin de partie.

## Fichiers principaux

- `main.cpp` : point d'entrée et boucle de jeu
- `Echiquier.h` / `Echiquier.cpp` : logique du plateau et des règles
- `Makefile.win` : compilation avec l'environnement MinGW/Dev-C++

## Compilation (Windows / MinGW)

```bash
mingw32-make -f Makefile.win
```

## Remarques

- le projet reste centré sur la logique de jeu,
- la sauvegarde/chargement passe par `jeu.txt`,
- les contrôles d'entrée méritent encore d'être enrichis pour une version entièrement robuste.

## Axes d'amélioration

1. Ajouter une suite de tests sur les règles critiques.
2. Séparer la logique de saisie console de la logique métier.
3. Renforcer les validations de fichiers et des coups saisis.
