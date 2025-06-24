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


double Ray::intersect_with(Object object) {
  if (Sphere *sphere = std::get_if<Sphere>(&object)) {
    return this->intersect_with_sphere(sphere);
  } else if (Plane *plane = std::get_if<Plane>(&object)) {
    return this->intersect_with_plane(plane);
  } else {
    std::cout << "Invalid Object" << std::endl;
  }
}


double Ray::intersect_with_sphere(Sphere *s) {
  Vector3 u = this->direction;
  double a = 1;
  double b = (s->center).dot(u) * -2;
  double c = s->center.length() * s->center.length() - s->radius * s->radius;
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

double Ray::intersect_with_plane(Plane *p) {
  double a = p->normal.x;
  double b = p->normal.y;
  double c = p->normal.z;
  
  double d = p->center.x;
  double e = p->center.y;
  double f = p->center.z;


  double ux = this->direction.x;
  double uy = this->direction.y;
  double uz = this->direction.z;
  double i = this->start.x;
  double j = this->start.y;
  double k = this->start.z;
  double t =
      (a * (d - i) + b * (e - j) + c * (f - k)) / (ux * a + uy * b + uz * c);
  return std::max(t, (double) 0);
}
