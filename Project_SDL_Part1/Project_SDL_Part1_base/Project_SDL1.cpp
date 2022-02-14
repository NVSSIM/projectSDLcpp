// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>

#include "application.h"
#include "Ground.h"

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {

  SDL_Surface* sdlSurfaceLoad = IMG_Load(path.c_str());
  if (!sdlSurfaceLoad) {
    throw std::runtime_error("load_surface_for(): SDL_Surface could not load! "
                             "IMG_Load Error: " +
                             std::string(IMG_GetError()));
  }

  SDL_Surface* sdlSurface =
      SDL_ConvertSurface(sdlSurfaceLoad, window_surface_ptr->format, 0);
  if (!sdlSurface) {
    throw std::runtime_error("load_surface_for(): SDL_Surface could not load! "
                             "IMG_Load Error: " +
                             std::string(SDL_GetError()));
  }

  return sdlSurface;
}
} // namespace
SDL_Surface* newSheepImage(SDL_Surface* window_surface_ptr_)
{
  return load_surface_for("../../media/sheep.png", window_surface_ptr_);
}
SDL_Surface* newWolfImage(SDL_Surface* window_surface_ptr_)
{
  return load_surface_for("../../media/wolf.png", window_surface_ptr_);
}
SDL_Surface* newShepImage(SDL_Surface* window_surface_ptr_)
{
  return load_surface_for("../../media/sheperd.png", window_surface_ptr_);
}
SDL_Surface* newDogImage(SDL_Surface* window_surface_ptr_)
{
  return load_surface_for("../../media/dog.png", window_surface_ptr_);
}
int ID = 0;

int newID()
{
  return ID++;
}











