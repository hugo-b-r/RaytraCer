// RaytraCer.cpp : définit le point d'entrée de l'application.
//

#include "RaytraCer.h"
// avoid sdl pooping
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void sdl_fail(std::string desc) {
  std::string msg = desc + ": " + SDL_GetError();
  std::cerr << msg << std::endl;
  throw new std::runtime_error(msg);
}

using namespace std;

int main() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    sdl_fail("Erreur lors de l'initialisation de la SDL");
  }

  shared_ptr<SDL_Window> window = std::shared_ptr<SDL_Window>(
      SDL_CreateWindow("RaytraCer", WINDOW_WIDTH, WINDOW_HEIGHT, 0),
      SDL_DestroyWindow);
  if (window == nullptr) {
    sdl_fail("Erreur lors de la création de la fenetre");
  }

  shared_ptr<SDL_Renderer> renderer = std::shared_ptr<SDL_Renderer>(
      SDL_CreateRenderer(window.get(), NULL), SDL_DestroyRenderer);
  if (renderer == nullptr) {
    sdl_fail("Erreur lors de la création du renderer");
  }

  // Main loop

  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }
    // Optionally, add rendering code here
    SDL_Delay(8);
  }

  SDL_Delay(3000);
  SDL_DestroyWindow(window.get());
  SDL_Quit();
  return EXIT_SUCCESS;
}
