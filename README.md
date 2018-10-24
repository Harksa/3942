# 3942
Pour ma dernière année de Master, j'ai réalisé un jeu sobrement intitulé "2942", pour le cours de Moteur de jeu. J'avais utilisé l'API QT pour ce faire.
Je n'étais pas satisfait d'avoir créé ce jeu en ayant eu le travail autant maché et j'étais vraiment intéressé à l'idée de créer tout moi même de A à Z; c'est pour cela que j'ai décidé de réaliser 3942.
3942 est un shooter en 2D, réalisé en C++ avec la bibliothèque SDL, ainsi qu'avec TinyXML.

## Installation
J'ai créé ce jeu sous Visual Studio 2018.
Pour pouvoir installer facilement la bibliothèque SDL, j'ai utilisé [VCPKG](https://github.com/Microsoft/vcpkg).
Une fois VCPKG installé, il faut installer les dépendances comme suit :

```
.\vcpkg install sdl2
.\vcpkg install sdl2-image
.\vcpkg install sdl2-mixer
.\vcpkg install tinyxml2
```

Les versions x86 sont installées par défaut, il est possible d'installer les versions x64 de ces derniers en rajoutant ``:x64-windows`` à la fin de chaque ligne de commandes.

# Done
- [x] Contrôle du personnage avec un joystick
- [x] Ecran de menu principal, jeu, Game Over et pause
- [x] Gestion des textures en fonctions d'un fichier xml
- [x] Génération de vague à partir d'un fichier xml
- [x] Balles ennemies et joueur
- [x] Mode deux joueurs
- [x] Gestion du score, de la vie et du HUD en général

# Todo
- [ ] Plusieurs variétés d'ennemis
- [ ] Création de plusieurs niveau
- [ ] Bosses
- [ ] Contrôle de l'IU avec la manette
