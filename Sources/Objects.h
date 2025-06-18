#ifndef OBJECTS_H

#define OBJECTS_H

#include "Vector3.h"
#include "Color.h"


class Sphere {
 public:
  Sphere(Vector3 center, double radius, Color color);

  Vector3 center;
  Color color;
  double radius;

  Vector3 Sphere::normal(Vector3 point);

 private:
};

class Screen {
 public:
  Screen::Screen();
  Screen::Screen(int width, int height, Vector3 pos);

  int getWidth();
  int getHeight();
  Vector3 getPos();

  Vector3 pixelDirectionFromOrigin(int x, int y);

  
 private:
  int width;
  int height;
  Vector3 pos;
};

#endif  // OBJECTS_H