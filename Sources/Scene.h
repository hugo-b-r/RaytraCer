#ifndef SCENE_H

#define SCENE_H

#include "Objects.h"
#include <vector>
#include "Scene.h"
#include <SDL3/SDL.h>

class Scene {
 public:
  Scene();
  Scene::Scene(int w, int h);


  std::vector<Object3D*> objets;
  Screen screen;
  Vector3 lumiere;


  int pixel_color(int x, int y, SDL_PixelFormatDetails format);

  std::vector<int> coloration(SDL_PixelFormatDetails format); 
};

#endif  // SCENE_H