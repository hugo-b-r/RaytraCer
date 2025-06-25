#ifndef OBJECTS_H

#define OBJECTS_H

#include <variant>

#include "Color.h"
#include "Ray.h"
#include "Vector3.h"

class Object3D {
 public:
  Vector3 center;

  Object3D::Object3D();
  Object3D::Object3D(Vector3 center);
};

class HittableObject3D : public Object3D {
 public:
  virtual double make_intersect(Ray *ray);
  Color color;
  HittableObject3D(Vector3 center);
  HittableObject3D(Vector3 center, Color color);
  HittableObject3D();
};

class Sphere : public HittableObject3D {
 public:
  Sphere(Vector3 center, double radius, Color color);

  double radius;

  Vector3 normal(Vector3 point);
  double make_intersect(Ray *ray) override;
};

class Screen : public Object3D {
 public:
  Screen::Screen();
  Screen::Screen(int width, int height, Vector3 pos);

  int getWidth();
  int getHeight();
  Vector3 getPos();

  Vector3 pixelDirectionFromOrigin(int x, int y);

 private:
  int width;
  int height;
};

class Plane : public HittableObject3D {
 public:
  Plane::Plane();
  Plane::Plane(Vector3 normal, Vector3 center, Color color);
  Vector3 normal;
  double make_intersect(Ray *ray) override;
};

// using Object = std::variant<Sphere, Plane>;

#endif  // OBJECTS_H