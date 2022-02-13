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
#include "ground.h"

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

namespace SDL_Utils {
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

application::application(unsigned int n_sheep, unsigned int n_wolf) {

  this->n_wolf = n_wolf;
  this->n_sheep = n_sheep;

  SDL_Window* sdlWindow = SDL_CreateWindow(
      "Moutons SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      frame_width, frame_height, SDL_WINDOW_OPENGL);
  this->window_ptr_ = sdlWindow;

  SDL_Surface* sdlSurface = SDL_GetWindowSurface(sdlWindow);
  this->window_surface_ptr_ = sdlSurface;

  //adding character
  for (int i = 0; i < n_sheep; ++i) {
    auto csheep = sheep(this->window_surface_ptr_);
    this->app_grnd->add_character(csheep);
  }
  for (int i = 0; i < n_wolf; ++i)
  {
    auto cwolf = wolf(this->window_surface_ptr_);
    this->app_grnd->add_character(cwolf);
  }
  auto cdog = sheperd_dog(this->window_surface_ptr_);
  this->app_grnd->add_character(cdog);

}



application::~application() { SDL_DestroyWindow(this->window_ptr_); }
int application::loop(unsigned int period) {

  while (SDL_GetTicks() < 1000) {
    this->app_grnd->update();
    SDL_UpdateWindowSurface(this->window_ptr_);
    SDL_Delay(frame_time* 1000);
  }
  return 0;
}


void character::draw(SDL_Surface* surface) {
  auto destRect = SDL_Rect{this->x_pos,this->y_pos, this->width, this->height}; //TODO w and h of png surface
  int result = SDL_BlitScaled(this->image_ptr_, NULL, surface, &destRect);
  if (result < 0) {
    throw std::runtime_error("draw(): SBlitScaled FAiled "
                             "SDL_BitScaled Error: " +
                             std::string(SDL_GetError()));
  }
}

void ground::setTargetMouton(wolf wolf){

  for (auto sheep : this->sheeps) {
      float distance_current_sheep  = wolf.getProximity(sheep);
      if(distance_current_sheep <= wolf.sheepToEatDistance){
      wolf.sheepToEat = sheep;
      wolf.sheepToEatDistance = distance_current_sheep;
    }
  }
}

void ground::sheperd_dog_fear(wolf wolf){
  float distance_from_dog = dog.getProximity(wolf);
  if(distance_from_dog<=WOLF_DISTANCE_FROM_DOG){
    wolf.dog_2_run_away = dog;
  }
}
void ground::setRunAway(sheep sheep)
{
    wolf nearestWolf = NULL;
    float distance_last_wolf  = INT_MAX;

    //check des loup
    for(auto wolf : this->wolfs)
    {
      float distance_current_wolf  = sheep.getProximity(wolf);

      if(distance_current_wolf <= SHEEP_PROXIMITY_RUN_AWAY){
        if(distance_current_wolf < distance_last_wolf){
          distance_last_wolf = distance_current_wolf;
        }
        nearestWolf = wolf;
      }

    }
    sheep.wolfToRunAway = nearestWolf;
}

void sheperd::move(){
  const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
  if(keyboard_state_array[SDL_SCANCODE_Z]){
    this->y_pos += SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_S]){
    this->y_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_Q]){
    this->x_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_D]){
    this->x_pos += SHEPERD_VELOCITY;
  }
  if(this->x_pos<0){
    this->x_pos=0;
  }
  if(this->y_pos<0){
    this->y_pos=0;
  }
}





