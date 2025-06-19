#include "Utilities.h"

#include <SDL3/SDL.h>
#include <iostream>

void sdl_fail(std::string desc) {
  std::string msg = desc + ": " + SDL_GetError();
  std::cerr << msg << std::endl;
  throw new std::runtime_error(msg);
}