# Projet académique — Jeu d'échecs multi-versions

Ce dépôt présente l'évolution d'un même projet académique autour du jeu d'échecs, réalisé en 2023, et décliné en trois étapes complémentaires :

1. une version console en C++,
2. une version graphique Qt/C++ avec mode réseau et IA locale,
3. une version Unity 3D avec intégration de Stockfish.

L'objectif est de mettre en valeur la progression technique du projet : logique métier, interface graphique, puis intégration d'un moteur d'échecs reconnu.

## Organisation du dépôt

```text
projects/
  console-cpp/                # Version console C++
  graphical-qt-online-ai/     # Version graphique Qt + mode online + IA locale
  graphical-unity-stockfish/  # Version Unity 3D + Stockfish
```

## Versions disponibles

### 1) `projects/console-cpp`

Version console jouable en C++.

Fonctionnalités principales :
- affichage textuel du plateau,
- validation des déplacements,
- gestion des coups spéciaux,
- détection de fin de partie,
- sauvegarde/chargement de partie.

### 2) `projects/graphical-qt-online-ai`

Version graphique avec Qt, mode local et mode en ligne.

Fonctionnalités principales :
- interface graphique du plateau,
- mode joueur contre joueur,
- mode joueur contre IA locale,
- lobby et communication TCP côté client/serveur.

### 3) `projects/graphical-unity-stockfish`

Version Unity 3D du jeu avec intégration de Stockfish.

Fonctionnalités principales :
- scène 3D interactive,
- déplacement visuel des pièces,
- intégration d'un moteur externe,
- base pour une IA plus robuste et plus paramétrable.

## Version recommandée pour démonstration

Pour une présentation GitHub claire, l'ordre de lecture conseillé est :

1. version console,
2. version Qt,
3. version Unity + Stockfish.

Cela permet de suivre naturellement l'évolution du projet.

## Pré-requis

Les dépendances varient selon le sous-projet :

- `console-cpp` : compilateur C++ compatible MinGW / Dev-C++,
- `graphical-qt-online-ai` : Qt pour le client, Visual Studio pour le serveur,
- `graphical-unity-stockfish` : Unity et environnement C# compatible.

## Fonctionnement général

Le projet illustre trois niveaux de maturité :

- la version console se concentre sur les règles du jeu,
- la version Qt ajoute l'interface graphique et le réseau,
- la version Unity présente la variante visuelle avec moteur externe.

Les sous-projets partagent la même intention pédagogique : réutiliser la même logique d'échecs sous des formes différentes selon la stack.


## English version

This repository showcases the evolution of an academic chess project, completed in 2023, across three complementary stages:

1. a C++ console version,
2. a Qt/C++ graphical version with network play and local AI,
3. a Unity 3D version with Stockfish integration.

The goal is to present the project as a clean, professional GitHub portfolio: one topic, three implementations, and a clear progression from game logic to graphical rendering and external engine integration.

## Note

The repository is presented as a final academic project portfolio, so only the completed versions and their documentation are kept in the root README.

## Licence et redistribution

Avant toute redistribution, vérifier les licences propres aux sous-projets et aux ressources tierces utilisées dans Unity, Qt et Stockfish.
