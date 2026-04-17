# Smart_Chess

Jeu d'échecs développé en Qt/C++ avec trois modes :

- partie locale joueur contre joueur,
- partie locale contre IA,
- mode en ligne avec lobby et serveur TCP.

## Organisation

Tout le code se trouve dans :

- `Client/` : interface Qt, IA locale et logique utilisateur,
- `Server/` : serveur TCP de gestion des parties en ligne.

## Points forts

- interface graphique Qt,
- gestion des pièces et des coups spéciaux,
- communication réseau avec messages JSON,
- base IA locale via MiniMax.

## Compilation

- ouvrir `Client/chess_AI.pro` dans Qt Creator,
- ouvrir `Server/ChessServer.sln` dans Visual Studio.

## Remarques techniques

- le projet est Windows-only à cause de WinSock et des APIs associées,
- le protocole réseau repose sur cJSON,
- les améliorations prioritaires concernent la robustesse des échanges réseau et la simplification du fichier `.pro`.

## Axes d'amélioration

1. Fiabiliser le protocole TCP et la gestion des erreurs réseau.
2. Unifier l'architecture logique du jeu avec la version console.
3. Ajouter des tests sur les coups spéciaux et les scénarios de fin de partie.
4. Nettoyer la configuration Qt et la rendre plus portable.
