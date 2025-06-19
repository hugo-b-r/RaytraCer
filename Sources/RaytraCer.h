// RaytraCer.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include "Scene.h"
#include "RealWindow.h"


#define SDL_MAIN_HANDLED

class RaytraCer {
 public:
  RaytraCer();
  void render();
  RealWindow window;
  Scene scene;

};

// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre
// programme.
