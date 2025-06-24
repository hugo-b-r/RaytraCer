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

  double intersect_with(Object object);
  double intersect_with_sphere(Sphere *s);
  double intersect_with_plane(Plane *p);
};

#endif  // RAY_H