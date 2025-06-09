#include "Objects.h"

Sphere::Sphere(Vector3 center, double radius) {
  this->center = center;
  this->radius = radius;
}

Screen::Screen(int width, int height, int scrDist, Vector3 origin) {
  this->width = width;
  this->height = height;
  this->scrDist = scrDist;
  this->pos = pos;
}

int Screen::getWidth() { return this->width; }

int Screen::getHeight() { return this->height; }

Vector3 Screen::pixelDirectionFromOrigin(
    int px, int py) {  // a free directionnal vector
  return Vector3((float)(px - (this->width)) / 2,
                 (float)(py - (this->height) / 2), 0) +
         this->pos;
}
