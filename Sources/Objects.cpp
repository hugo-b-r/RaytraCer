#include "Objects.h"



Vector3 Sphere::normal(Vector3 point) {
  return (point - this->center).unit();
}

Sphere::Sphere(Vector3 center, double radius, Color color) {
  this->center = center;
  this->radius = radius;
  this->color = color;
}

Screen::Screen() {
  this->width = 2000;
  this->height = 1000;
  this->pos = Vector3(0, 0, 1000);
}

Screen::Screen(int width, int height, Vector3 pos) {
  this->width = width;
  this->height = height;
  this->pos = pos;
}

int Screen::getWidth() { return this->width; }

int Screen::getHeight() { return this->height; }

Vector3 Screen::getPos() { return this->pos; }

Vector3 Screen::pixelDirectionFromOrigin(
    int x, int y) {  // a free directionnal vector
  return Vector3((double)x - (double)(this->width) / (double)2,
                 (double)y - (double)(this->height) / (double)2, (double)0) +
         this->pos;
}

