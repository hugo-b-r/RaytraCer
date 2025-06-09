#include "Vector3.h"

#include <cmath>

Vector3::Vector3(double a, double b, double c) {
  x = a;
  y = b;
  z = c;
}

Vector3::Vector3() {
  x = 0;
  y = 0;
  z = 0;
}

Vector3 Vector3::fromOrigin(Vector3 p) { return p; }

Vector3 Vector3::operator+(const Vector3& vec3) {
  return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
}

Vector3 Vector3::operator+=(const Vector3& vec3) {
  return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
}
Vector3 Vector3::operator-(const Vector3& vec3) {
  return Vector3(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z);
}

Vector3 Vector3::operator-=(const Vector3& vec3) {
  return Vector3(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z);
}

Vector3 Vector3::operator*(const int i) {
  return Vector3(this->x * i, this->y * i, this->z * i);
}
Vector3 Vector3::operator*(const double i) {
  return Vector3(this->x * i, this->y * i, this->z * i);
}
Vector3 Vector3::operator*(const float i) {
  return Vector3(this->x * i, this->y * i, this->z * i);
}

Vector3 Vector3::operator/(const double c) {
  return Vector3(this->x / c, this->y / c, this->z / c);
}
double Vector3::dot(Vector3& vec3) {
  return x * vec3.x + y * vec3.y + z * vec3.z;
}

Vector3 Vector3::cross(Vector3& vec3) {
  return Vector3(y * vec3.z - z * vec3.y, z * vec3.x - x * vec3.z,
                 x * vec3.y - y * vec3.x);
}

double Vector3::length_squared() { return x * x + y * y + z * z; }

double Vector3::length() { return sqrt(this->length_squared()); }

Vector3 Vector3::unit() { return *this / this->length(); }

Vector3 Vector3::reflection(Vector3 normal) {
  return *this - normal * 2 * (this->dot(normal));
}