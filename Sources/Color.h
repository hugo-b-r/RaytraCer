#pragma once
#include <cstdint>


class Color {
 public:
  Color();
  Color(int red, int green, int blue);

  void setRed(int red);
  void setGreen(int green);
  void setBlue(int blue);

  int getRed();
  int getGreen();
  int getBlue();

  Color operator*(double t);

 private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};