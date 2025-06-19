#include "RealWindow.h"
#include "Utilities.h"
#include <iostream>

RealWindow::RealWindow() {
  int width = 1000;
  int height = 500;
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    sdl_fail("Erreur lors de l'initialisation de la SDL");
  }

  this->window = std::shared_ptr<SDL_Window>(
      SDL_CreateWindow("RaytraCer", width, height, 0),
      SDL_DestroyWindow);
  if (window == nullptr) {
    sdl_fail("Erreur lors de la création de la fenetre");
  }

  this->renderer = std::shared_ptr<SDL_Renderer>(
      SDL_CreateRenderer(window.get(), NULL), SDL_DestroyRenderer);
  if (renderer == nullptr) {
    sdl_fail("Erreur lors de la création du renderer");
  }

  this->width = width;
  this->height = height;

  this->format = SDL_PIXELFORMAT_RGBA8888;
}


RealWindow::RealWindow(int w, int h, SDL_PixelFormat format) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    sdl_fail("Erreur lors de l'initialisation de la SDL");
  }

  this->window = std::shared_ptr<SDL_Window>(
      SDL_CreateWindow("RaytraCer", w, h, 0), SDL_DestroyWindow);
  if (window == nullptr) {
    sdl_fail("Erreur lors de la création de la fenetre");
  }

  this->renderer = std::shared_ptr<SDL_Renderer>(
      SDL_CreateRenderer(window.get(), NULL), SDL_DestroyRenderer);
  if (renderer == nullptr) {
    sdl_fail("Erreur lors de la création du renderer");
  }

  this->width = w;
  this->height = h;

  this->format = format;
}


RealWindow::~RealWindow() {
  std::cout << "Closing the window..." << std::endl;
  SDL_DestroyRenderer(this->renderer.get());
  SDL_DestroyWindow(this->window.get());
  SDL_Quit();
  std::cout << "Exited !" << std::endl;
}