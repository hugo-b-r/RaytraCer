#ifndef VECTOR3_H

#define VECTOR3_H


class Vector3 {
 public:
  double x;
  double y;
  double z;

  Vector3(double a, double b, double c);
  Vector3();
  Vector3 fromOrigin(Vector3 p);

  Vector3 operator+(const Vector3& vec3);
  Vector3 operator+=(const Vector3& vec3);
  Vector3 operator-(const Vector3& vec3);
  Vector3 operator-=(const Vector3& vec3);
  Vector3 operator*(const int i);
  Vector3 operator*(const double i);
  Vector3 operator*(const float i);
  Vector3 operator/(const double c);

  double dot(Vector3& vec3);
  Vector3 cross(Vector3& vec3);

  double length_squared();
  double length();
  Vector3 unit();

  
  Vector3 reflection(Vector3 normal);
};

#endif  // VECTOR3_H