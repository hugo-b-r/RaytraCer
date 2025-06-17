#include "Scene.h"
#include "Ray.h"


Scene::Scene() {
  this->lumiere = Vector3(45, -50, -40);
  this->objets = {Sphere(Vector3(0, 1, 10), 1.0)};
  this->screen = Screen();
}


int Scene::pixel_color(int x, int y, SDL_PixelFormatDetails format) {
  Vector3 u = this->screen.pixelDirectionFromOrigin(x, y).unit();
  Ray r = Ray(Vector3(0, 0, 0), u);
  double intersec = r.intersect_with(this->objets[0]);
  if (intersec != 0) {
    Vector3 OM = u * intersec;
    Vector3 ML = this->lumiere - OM;
    Vector3 l = ML.unit();
    Vector3 n = (OM - this->objets[0].center).unit();
    Color color = this->objets[0].color * std::max(n.dot(l), (double)0);
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

