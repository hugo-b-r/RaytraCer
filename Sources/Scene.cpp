#include "Scene.h"
#include "Ray.h"
#include <iostream>

#include <variant>



Scene::Scene() {
  this->lumiere = Vector3(45, -50, -40);
  this->objets = {&Sphere(Vector3(2, 0, 7), 1.0, Color(0, 255, 0)),
                  &Sphere(Vector3(-2, 0, 7), 1.0, Color(0, 0, 255)),
                  &Sphere(Vector3(0, 0, 10), 2.0, Color(255, 0, 0))};
  this->screen = Screen();
}

Scene::Scene(int w, int h) {
  this->lumiere = Vector3(45, -50, -40);
  this->objets = {&Sphere(Vector3(2, 0, 7), 1.0, Color(0, 255, 0)),
                  &Sphere(Vector3(-2, 0, 7), 1.0, Color(0, 0, 255)),
                  &Sphere(Vector3(0, 0, 10), 2.0, Color(255, 0, 0))};
  this->screen = Screen(w, h, Vector3(0, 0, 1000));
}


int Scene::pixel_color(int x, int y, SDL_PixelFormatDetails format) {
  Vector3 u = this->screen.pixelDirectionFromOrigin(x, y).unit();
  double t = 0;
  int t_obj = 1;
  double intersec = 0;
  for (int i = 0; i < this->objets.size(); i++) {
    Ray r = Ray(Vector3(0, 0, 0), u);
    intersec = r.intersect_with(this->objets[i]);
    if ((intersec != 0 && intersec < t) || (intersec != 0 && t == 0)) {
      t = intersec;
      t_obj = i;
    }
  }
  Object drawn_sphere = this->objets[t_obj]; 
  if (t != 0) {
    Vector3 OM = u * t;
    Vector3 ML = this->lumiere - OM;
    Vector3 l = ML.unit();
    Vector3 n = (OM - this->objets[t_obj]->center).unit();
    Color color = this->objets[t_obj]->color * std::max(n.dot(l), (double)0);    
    
    for (int i = 0; i < this->objets.size(); i++) {
      if (Ray(OM, l).intersect_with(this->objets[i]) != 0 &&
          i != t_obj) {
        color = Color(50, 50 ,50);
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

