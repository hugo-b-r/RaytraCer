#include "Objects.h"




 Object3D::Object3D() { this->center = Vector3(0, 0, 0); }

 
 Object3D::Object3D(Vector3 center) { this->center = center; }


Vector3 Sphere::normal(Vector3 point) {
  return (point - this->center).unit();
}

Sphere::Sphere(Vector3 center, double radius, Color color) : Object3D(center) {
  this->radius = radius;
  this->color = color;
}

Screen::Screen() : Object3D(Vector3(0, 0, 1000)) {
  this->width = 2000;
  this->height = 1000;
}

Screen::Screen(int width, int height, Vector3 pos) {
  this->width = width;
  this->height = height;
  this->center = pos;
}

int Screen::getWidth() { return this->width; }

int Screen::getHeight() { return this->height; }

Vector3 Screen::getPos() { return this->center; }

Vector3 Screen::pixelDirectionFromOrigin(
    int x, int y) {  // a free directionnal vector
  return Vector3((double)x - (double)(this->width) / (double)2,
                 (double)y - (double)(this->height) / (double)2, (double)0) +
         this->center;
}



Plane::Plane() {
    this->center = Vector3(0, 0, 0);
    this->color = Color(255, 0, 0);
    this->normal = Vector3(0, 0, 1);
}

Plane::Plane(Vector3 normal, Vector3 center, Color color) {
  this->center = center;
  this->color = color;
  this->normal = normal;
}
