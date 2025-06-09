#pragma once

class Vector2 {
 public:
  double x;
  double y;

  Vector2(double a, double b);
  Vector2();

  Vector2 operator+(const Vector2 &vec2);
  Vector2 operator+=(const Vector2 &vec2);
  Vector2 operator-(const Vector2 &vec2);
  Vector2 operator-=(const Vector2 &vec2);
  Vector2 operator/(const double c);

  double dot(const Vector2 &vec2);

  double length_squared();
  double length();
  Vector2 unit();
};

using Point2 = Vector2;