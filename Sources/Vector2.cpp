#include "Vector2.h"

#include <cmath>

Vector2::Vector2(double a, double b) {
  x = a;
  y = b;
}

Vector2::Vector2() {
  x = 0;
  y = 0;
}

Vector2 Vector2::operator+(const Vector2& vec2) {
  return Vector2(this->x + vec2.x, this->y + vec2.y);
}

Vector2 Vector2::operator+=(const Vector2& vec2) {
  return Vector2(this->x + vec2.x, this->y + vec2.y);
}
Vector2 Vector2::operator-(const Vector2& vec2) {
  return Vector2(this->x - vec2.x, this->y - vec2.y);
}

Vector2 Vector2::operator-=(const Vector2& vec2) {
  return Vector2(this->x - vec2.x, this->y - vec2.y);
}

Vector2 Vector2::operator/(const double c) {
  return Vector2(this->x / c, this->y / c);
}

double Vector2::dot(const Vector2& vec2) { return x * vec2.x + y * vec2.y; }

double Vector2::length_squared() { return x * x + y * y; }

double Vector2::length() { return sqrt(this->length_squared()); }

Vector2 Vector2::unit() { return *this / this->length(); }
