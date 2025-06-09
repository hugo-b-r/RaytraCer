#include "Image.h"

#include "RaytraCer.h"

Image::Image() {
  this->pxs = new Color*[WINDOW_WIDTH];
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    this->pxs[i] = new Color[WINDOW_HEIGHT];
  }
  width = WINDOW_WIDTH;
  height = WINDOW_HEIGHT;
}

Image::Image(int width, int height) {
  this->pxs = new Color*[width];
  for (int i = 0; i < width; i++) {
    this->pxs[i] = new Color[height];
  }
  this->width = width;
  this->height = height;
}

Image::~Image() { delete[] this->pxs; }

Color Image::getColor(int x, int y) { return this->pxs[x][y]; }

void Image::setColor(
    int x, int y,
    Color color) {  // maybe catch unwanted access to external part of the table
  this->pxs[x][y] = color;
}