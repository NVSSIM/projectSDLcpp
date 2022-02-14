#include "application.h"
#include "Character.h"
#include "RandomPosition.h"

//
// Created by etsugo on 14/02/2022.
//
application::application(unsigned int n_sheep, unsigned int n_wolf) {

  this->n_wolf = n_wolf;
  this->n_sheep = n_sheep;

  SDL_Window* sdlWindow = SDL_CreateWindow(
      "Moutons SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      frame_width, frame_height, SDL_WINDOW_OPENGL);
  this->window_ptr_ = sdlWindow;

  SDL_Surface* sdlSurface = SDL_GetWindowSurface(sdlWindow);
  this->window_surface_ptr_ = sdlSurface;
    this->randomPosition = {frame_boundary, static_cast<float>(sdlSurface->w - frame_boundary),frame_boundary, static_cast<float>(sdlSurface->h - frame_boundary)};


  this->app_grnd = new Ground(sdlSurface);


  //adding Character
  //auto cShep = Sheperd();
  auto cShep = std::make_shared<Sheperd>(newID(),newShepImage(window_surface_ptr_),app_grnd,this->randomPosition.getRandomPosition());
  this->app_grnd->add_character(cShep);
  this->app_grnd->add_character(std::make_shared<Sheperd_dog>(newID(), newDogImage(window_surface_ptr_), app_grnd, cShep,this->randomPosition.getRandomPosition()));
  for (int i = 0; i < n_sheep; ++i) {
    this->app_grnd->add_character(std::make_shared<Sheep>(newID(),newSheepImage(window_surface_ptr_),app_grnd,this->randomPosition.getRandomPosition(),app_grnd,this->randomPosition));
  }
  for (int i = 0; i < n_wolf; ++i)
  {
    this->app_grnd->add_character(std::make_shared<Wolf>(newID(),newWolfImage(window_surface_ptr_),app_grnd,app_grnd,this->randomPosition.getRandomPosition()));
  }

}

application::~application() { SDL_DestroyWindow(this->window_ptr_); }

int application::loop(unsigned int period) {
    auto currentTime = SDL_GetTicks();
  while (currentTime < period) {
    this->app_grnd->update();
    SDL_UpdateWindowSurface(this->window_ptr_);
    SDL_Delay(frame_time* 1000);
      currentTime = SDL_GetTicks();
  }
  return 0;
}
