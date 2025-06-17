// RaytraCer.cpp : définit le point d'entrée de l'application.
//

#include "RaytraCer.h"
// avoid sdl pooping
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_surface.h>

#include "Color.h"
#include "Ray.h"
#include "Scene.h"
#include "Vector3.h"

#include <ctime>



void sdl_fail(std::string desc) {
  std::string msg = desc + ": " + SDL_GetError();
  std::cerr << msg << std::endl;
  throw new std::runtime_error(msg);
}


void render(Scene scene, SDL_Renderer* renderer) {
  SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA8888;
  std::vector<int> image(scene.screen.getWidth() * scene.screen.getHeight());
  image = scene.coloration(*SDL_GetPixelFormatDetails(format));
  SDL_Surface* surface =
      SDL_CreateSurfaceFrom(scene.screen.getWidth(), scene.screen.getHeight(),
                            format, image.data(), scene.screen.getWidth() * 4);
    
  if (surface == nullptr) {
    sdl_fail("Erreur lors de la création de la surface");
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (texture == nullptr) {
    sdl_fail("Erreur lors de la création de la texture");
  }
  SDL_SetRenderTarget(renderer, texture);
  SDL_RenderTexture(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}


using namespace std;

int main() {
  Scene scene = Scene();

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    sdl_fail("Erreur lors de l'initialisation de la SDL");
  }

  shared_ptr<SDL_Window> window = std::shared_ptr<SDL_Window>(
      SDL_CreateWindow("RaytraCer", scene.screen.getWidth(), scene.screen.getHeight(), 0),
      SDL_DestroyWindow);
  if (window == nullptr) {
    sdl_fail("Erreur lors de la création de la fenetre");
  }

  shared_ptr<SDL_Renderer> renderer = std::shared_ptr<SDL_Renderer>(
      SDL_CreateRenderer(window.get(), NULL), SDL_DestroyRenderer);
  if (renderer == nullptr) {
    sdl_fail("Erreur lors de la création du renderer");
  }

  std::cout << "Welcome in this little raytracer !" << std::endl;
  

  // Main loop

  bool running = true;
  SDL_Event event;

  
  std::clock_t c_start = std::clock();
  render(scene, renderer.get());
  std::clock_t c_end = std::clock();

  long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
  std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      } else if (event.type == SDL_EVENT_KEY_DOWN) {
        SDL_Keycode key_code = event.key.key;
        switch (key_code) { 
        case SDLK_R:
            std::clock_t c_start2 = std::clock();
            render(scene, renderer.get());
            std::clock_t c_end2 = std::clock();

            long double time_elapsed_ms2 =
                1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
            std::cout << "CPU time used: " << time_elapsed_ms2 << " ms\n";
            break;
        }

      }
    }
    // Optionally, add rendering code here
  }

  SDL_DestroyWindow(window.get());
  SDL_Quit();
  return EXIT_SUCCESS;
}
