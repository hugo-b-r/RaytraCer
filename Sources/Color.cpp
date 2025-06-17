#include "Color.h"

Color::Color() {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
}

Color::Color(int red, int green, int blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}

void Color::setRed(int red) { this->red = red; }

void Color::setGreen(int green) { this->green = green; }
void Color::setBlue(int blue) { this->blue = blue; }

int Color::getRed() { return this->red; }

int Color::getGreen() { return this->green; }

int Color::getBlue() { return this->blue; }

Color Color::operator*(double t) {
  return Color(t * this->red, t * this->green, t * this->blue);
}