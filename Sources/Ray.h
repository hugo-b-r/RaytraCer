#include "Vector3.h"
#pragma once

#include "Objects.h"
#include "Vector3.h"

class Ray {
 public:
  Vector3 start;
  Vector3 direction;

  Ray();
  Ray(Vector3 start, Vector3 diretion);
  Vector3 at(double t);

  double intersect_with(Sphere s);
};
