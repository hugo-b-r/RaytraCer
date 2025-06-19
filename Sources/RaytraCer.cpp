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
#include "Utilities.h"
#include "RealWindow.h"

#include <ctime>



RaytraCer::RaytraCer()
    : window(2000, 1000, SDL_PIXELFORMAT_RGBA8888), scene(2000, 1000) {}

void RaytraCer::render() {
  std::clock_t c_start = std::clock();

  SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA8888;
  std::vector<int> image(this->scene.screen.getWidth() *
                         this->scene.screen.getHeight());
  image = this->scene.coloration(*SDL_GetPixelFormatDetails(format));
  SDL_Surface* surface = SDL_CreateSurfaceFrom(
      this->scene.screen.getWidth(), this->scene.screen.getHeight(), format,
      image.data(), this->scene.screen.getWidth() * 4);

  if (surface == nullptr) {
    sdl_fail("Erreur lors de la création de la surface");
  }
  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(this->window.renderer.get(), surface);
  if (texture == nullptr) {
    sdl_fail("Erreur lors de la création de la texture");
  }
  SDL_SetRenderTarget(this->window.renderer.get(), texture);
  SDL_RenderTexture(this->window.renderer.get(), texture, NULL, NULL);
  SDL_RenderPresent(this->window.renderer.get());
  
  
  std::clock_t c_end = std::clock();

  long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
  std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";
}


using namespace std;

int main() {
  RaytraCer rt;
  std::cout << "Welcome in this little raytracer !" << std::endl;
  

  // Main loop

  bool running = true;
  SDL_Event event;

  rt.render();
  
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      } else if (event.type == SDL_EVENT_KEY_DOWN) {
        SDL_Keycode key_code = event.key.key;
        switch (key_code) { 
        case SDLK_R:
            rt.render();
            break;
        }

      }
    }
    // Optionally, add rendering code here
  }


  return EXIT_SUCCESS;
}
