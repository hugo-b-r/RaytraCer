#include "Ray.h"

#include <algorithm>

Ray::Ray() {
  this->start = Vector3(0, 0, 0);
  this->direction = Vector3(0, 0, 0);
}

Ray::Ray(Vector3 start, Vector3 direction) {
  this->start = start;
  this->direction = direction;
}

Vector3 Ray::at(double t) { return this->start + this->direction * t; }


double Ray::intersect_with(Sphere s) {
  Vector3 u = this->direction;
  double a = 1;
  double b = (s.center).dot(u) * -2;
  double c = s.center.length() * s.center.length() - s.radius * s.radius;
  double delta = b * b - 4 * a * c;
  if (delta == 0) {
    return std::max(-b / (2 * a), (double)0);
  } else if (delta >= 0) {
    double x1 = (-b - sqrt(delta)) / (2 * a);
    double x2 = (-b + sqrt(delta)) / (2 * a);
    double root_min = std::min(x1, x2);
    double root_max = std::max(x1, x2);
    if (root_min >= 0) {
      return root_min;
    } else {
      return root_max;
    }
  } else {
    return 0;
  }
  return 0;
}