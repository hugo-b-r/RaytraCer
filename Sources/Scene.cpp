#include "Scene.h"

#include <iostream>
#include <variant>

#include "Ray.h"

Scene::Scene() {
  this->lumiere = Vector3(45, -50, -40);
  this->objets = {
      std::make_shared<Sphere>(Sphere(Vector3(2, 0, 7), 1.0, Color(0, 255, 0))),
      std::make_shared<Sphere>(
          Sphere(Vector3(-2, 0, 7), 1.0, Color(0, 0, 255))),
      std::make_shared<Sphere>(
          Sphere(Vector3(0, 0, 10), 2.0, Color(255, 0, 0)))};

  this->screen = Screen();
}

Scene::Scene(int w, int h) {
  this->lumiere = Vector3(45, -50, -40);
  this->objets = {
      std::make_shared<Sphere>(
          Sphere(Vector3(2, 0, 7), 1.0, Color(80, 255, 80))),
      std::make_shared<Sphere>(
          Sphere(Vector3(-2, 0, 7), 1.0, Color(80, 80, 255))),
      std::make_shared<Sphere>(
          Sphere(Vector3(0, 0, 10), 2.0, Color(255, 80, 80))),
      std::make_shared<Plane>(
          Plane(Vector3(0, -1, 0), Vector3(0, 2, 50), Color(200, 200, 200))),
  };
  this->screen = Screen(w, h, Vector3(0, 0, 1000));
}

int Scene::pixel_color(int x, int y, SDL_PixelFormatDetails format) {
  Vector3 u = this->screen.pixelDirectionFromOrigin(x, y).unit();
  double t = 0;
  int i_obj = 1;
  double intersec = 0;
  for (int i = 0; i < this->objets.size(); i++) {
    Ray r = Ray(Vector3(0, 0, 0), u);
    intersec = this->objets[i].get()->make_intersect(&r);
    if ((intersec != 0 && intersec < t) || (intersec != 0 && t == 0)) {
      t = intersec;
      i_obj = i;
    }
  }
  if (t != 0) {
    Vector3 OM = u * t;
    Vector3 ML = this->lumiere - OM;
    Vector3 l = ML.unit();
    Vector3 n = this->objets[i_obj]->normal(OM);
    Color color =
        this->objets[i_obj].get()->color * std::max(n.dot(l), (double)0);

    for (int i = 0; i < this->objets.size(); i++) {
      Ray r(OM, l);
      double t_3 = this->objets[i].get()->make_intersect(&r);
      if (t_3 > 0 && i != i_obj) {
        color = Color(0, 0, 0);
      }
    }
    return SDL_MapRGB(&format, NULL, color.getRed(), color.getGreen(),
                      color.getBlue());
  } else {
    return SDL_MapRGB(&format, NULL, 50, 50, 50);
  }
}

std::vector<int> Scene::coloration(SDL_PixelFormatDetails format) {
  // to store  a bitmap image in rgb
  std::vector<int> image(this->screen.getWidth() * this->screen.getHeight());
  for (int x = 0; x < this->screen.getWidth(); x++) {
    for (int y = 0; y < this->screen.getHeight(); y++) {
      image[y * this->screen.getWidth() + x] = pixel_color(x, y, format);
    }
  }
  return image;
}
