#pragma once

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
  int red;
  int green;
  int blue;
};