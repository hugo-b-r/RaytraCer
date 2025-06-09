#include <vector>

#include "Objects.h"

class Scene {
 private:
  Vector3 lumiere;
  std::vector<Sphere> objets;
  Screen screen;
};