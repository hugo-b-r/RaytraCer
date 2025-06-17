#ifndef RAY_H

#define RAY_H


#include "Vector3.h"
#include "Objects.h"

class Ray {
 public:
  Vector3 start;
  Vector3 direction;

  Ray();
  Ray(Vector3 start, Vector3 diretion);
  Vector3 at(double t);

  double intersect_with(Sphere s);
};

#endif  // RAY_H