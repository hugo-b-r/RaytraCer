#include "Ray.h"

#include <algorithm>
#include <iostream>

Ray::Ray() {
  this->start = Vector3(0, 0, 0);
  this->direction = Vector3(0, 0, 0);
}

Ray::Ray(Vector3 start, Vector3 direction) {
  this->start = start;
  this->direction = direction;
}

Vector3 Ray::at(double t) { return this->start + this->direction * t; }
