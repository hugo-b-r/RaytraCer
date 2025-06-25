#include "Objects.h"

#include <iostream>

Object3D::Object3D() : center(Vector3(0, 0, 0)) {}

Object3D::Object3D(Vector3 center) : center(center) {}

double HittableObject3D::make_intersect(Ray *ray) { return 0; }
Vector3 HittableObject3D::normal(Vector3 point) { return Vector3(1, 0, 0); }
HittableObject3D::HittableObject3D(Vector3 center) : Object3D(center) {}
HittableObject3D::HittableObject3D(Vector3 center, Color color)
    : color(color), Object3D(center) {}
HittableObject3D::HittableObject3D() : Object3D() {}

Sphere::Sphere(Vector3 center, double radius, Color color)
    : radius(radius), HittableObject3D(center, color) {
  this->radius = radius;
}

double Sphere::make_intersect(Ray *ray) {
  Vector3 u = ray->direction;
  double a = 1;
  double b = (this->center).dot(u) * -2;
  double c = this->center.length() * this->center.length() -
             this->radius * this->radius;
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

Vector3 Sphere::normal(Vector3 point) { return (point - this->center).unit(); }

Screen::Screen() : Object3D(Vector3(0, 0, 1000)), width(2000), height(1000) {}

Screen::Screen(int width, int height, Vector3 pos)
    : width(width), height(height), Object3D(pos) {}

int Screen::getWidth() { return this->width; }

int Screen::getHeight() { return this->height; }

Vector3 Screen::getPos() { return this->center; }

Vector3 Screen::pixelDirectionFromOrigin(int x,
                                         int y) {  // a free directionnal vector
  return Vector3((double)x - (double)(this->width) / (double)2,
                 (double)y - (double)(this->height) / (double)2, (double)0) +
         this->center;
}

Plane::Plane()
    : norm(Vector3(0, 0, 1)),
      HittableObject3D(Vector3(0, 0, 0), Color(255, 0, 0)) {}

Plane::Plane(Vector3 normal, Vector3 center, Color color)
    : norm(normal), HittableObject3D(center, color) {}

double Plane::make_intersect(Ray *ray) {
  double a = this->norm.x;
  double b = this->norm.y;
  double c = this->norm.z;

  double d = this->center.x;
  double e = this->center.y;
  double f = this->center.z;

  double ux = ray->direction.x;
  double uy = ray->direction.y;
  double uz = ray->direction.z;
  double i = ray->start.x;
  double j = ray->start.y;
  double k = ray->start.z;
  double t =
      (a * (d - i) + b * (e - j) + c * (f - k)) / (ux * a + uy * b + uz * c);
  return std::max(t, (double)0);
}

Vector3 Plane::normal(Vector3 point) { return this->norm.unit(); }