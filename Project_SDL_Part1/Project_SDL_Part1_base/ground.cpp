#include "ground.h"

#include <utility>
#include <vector>
#include <SDL.h>
#include "sheep.h"
#include "Project_SDL1.h"
#include "sheperd.h"
#include "sheperd_dog.h"
//
// Created by etsugo on 12/02/2022.
//
ground::ground(SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
}

ground::~ground() {
  for (int i = 0; i < character.size(); ++i) {
    delete character[i];
  }
}

void ground::update() {
  // Fill the surfaces to reset image
  const auto rect = SDL_Rect{0,0, frame_width, frame_height};
  auto color = SDL_MapRGB(this->window_surface_ptr_->format,10,255,10);
  SDL_FillRect(this->window_surface_ptr_, &rect, color);

  //foreach character -> character.onNewTik => reset les proximity a INT_MAX, decremente le temps du sex
  //Ordre : berger, chien, moutons, loups
  for (auto *canimal: this->sheeps)
  {
    canimal->move();
    canimal->draw();
  }
  for (auto *canimal: this->wolfs)
  {
    canimal->move();
    canimal->draw();
  }

}

void ground::sheepHavingBaby(sheep sheep1)
{
  sheep newSheep = sheep(nullptr, nullptr,
                         nullptr);//create a baby sheep on the same position
  newSheep.corner = sheep1.corner;
  add_character(newSheep);
}
void ground::sheepHaveBeenEat(sheep sheep) {
  remove_character(std::move(sheep));
}
void ground::wolfIsHungry(wolf wolf) {
  remove_character(std::move(wolf));
}
void ground::add_character(wolf character)
{
  this->wolfs.push_back(&character);
}
void ground::add_character(sheep character)
{
  this->sheeps.push_back(&character);
}
void ground::add_character(sheperd_dog character)
{
  this->dog = character;
}
void ground::add_character(sheperd character)
{
  this->playable_sheperd = character;
}
void ground::remove_character(wolf wolf1) {} //TODO
void ground::remove_character(sheep sheep) {}//TODO

std::vector<sheep> ground::getSheeps() { return this->sheeps; }
