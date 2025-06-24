#ifndef OBJECTS_H

#define OBJECTS_H

#include "Vector3.h"
#include "Color.h"

#include <variant>


class Object3D {

public:
  Vector3 center;

  Object3D::Object3D();
  Object3D::Object3D(Vector3 center);
};


class Sphere : public Object3D {
 public:
  Sphere(Vector3 center, double radius, Color color);

  Color color;
  double radius;

  Vector3 Sphere::normal(Vector3 point);

 private:
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

class Plane : public Object3D {
	public: 
		Plane::Plane();
        Plane::Plane(Vector3 normal, Vector3 center, Color color);
        Vector3 normal;
        Color color;   
};



using Object = std::variant<Sphere, Plane>;

#endif  // OBJECTS_H