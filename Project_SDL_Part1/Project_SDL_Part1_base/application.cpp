#include "application.h"
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

  //adding Character
  auto cShep = Sheperd(newID(),newShepImage(window_surface_ptr_),app_grnd);
  this->app_grnd->add_character(&cShep);
  auto cdog =
      Sheperd_dog(newID(), newDogImage(window_surface_ptr_), app_grnd, &cShep);
  this->app_grnd->add_character(&cdog);
  for (int i = 0; i < n_sheep; ++i) {
    auto csheep = Sheep(newID(),newSheepImage(window_surface_ptr_),app_grnd,app_grnd);
    this->app_grnd->add_character(&csheep);
  }
  for (int i = 0; i < n_wolf; ++i)
  {
    auto cwolf = Wolf(newID(),newWolfImage(window_surface_ptr_),app_grnd,app_grnd);
    this->app_grnd->add_character(&cwolf);
  }


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