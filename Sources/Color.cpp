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

Color::Color(uint8_t red, uint8_t green, uint8_t blue)
    : red(red), blue(blue), green(green) {}

void Color::setRed(int red) { this->red = red; }

void Color::setGreen(int green) { this->green = green; }
void Color::setBlue(int blue) { this->blue = blue; }

int Color::getRed() const { return this->red; }

int Color::getGreen() const { return this->green; }

int Color::getBlue() const { return this->blue; }

Color Color::operator*(double t) {
  return Color((int) (t * this->red), (int) (t * this->green), (int) (t * this->blue));
}