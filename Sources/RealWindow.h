#ifndef REALWINDOW_H

#define REALWINDOW_H

#include <memory>
#include <SDL3/SDL.h>

class RealWindow {
 public:
  RealWindow();
  RealWindow(int w, int height, SDL_PixelFormat format);

  ~RealWindow();

  std::shared_ptr<SDL_Renderer> renderer;
  std::shared_ptr<SDL_Window> window;
 private:

  
  int width;
  int height;

  SDL_PixelFormat format;
};

#endif