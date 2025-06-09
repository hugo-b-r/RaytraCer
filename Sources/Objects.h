#pragma once

#include "Vector3.h"

class Sphere {
 public:
  Sphere(Vector3 center, double radius);

  Vector3 center;

  double radius;

 private:
};

class Screen {
 public:
  Screen(int width, int height, int scrDist, Vector3 origin);

  int getWidth();
  int getHeight();

  Vector3 pixelDirectionFromOrigin(int px, int py);

 private:
  int width;
  int height;
  int scrDist;
  Vector3 pos;
};