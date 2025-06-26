#ifndef SCENE_H

#define SCENE_H

#include "Objects.h"
#include <vector>
#include "Scene.h"
#include <SDL3/SDL.h>
#include <memory>

class Scene {
 public:
  Scene();
  Scene::Scene(int w, int h);


  std::vector<std::shared_ptr<HittableObject3D>> objets;
  Screen screen;
  Vector3 lumiere;


  int pixel_color(int x, int y, SDL_PixelFormatDetails format);

  std::vector<int> coloration(SDL_PixelFormatDetails format); 
};

#endif  // SCENE_H