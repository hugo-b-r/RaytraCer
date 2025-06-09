#pragma once

#include "Color.h"

class Image {
 private:
  Color** pxs;
  int width;
  int height;

 public:
  Image();
  Image(int width, int height);

  Color getColor(int x, int y);
  void setColor(int x, int y, Color color);

  ~Image();
};