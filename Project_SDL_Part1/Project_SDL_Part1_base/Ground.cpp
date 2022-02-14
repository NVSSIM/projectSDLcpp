#include "Ground.h"

#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>
#include "Sheep.h"
#include "Project_SDL1.h"
#include "Sheperd.h"
#include "Sheperd_dog.h"

constexpr float DISTANCE_TO_EAT_SHEEP = 3;
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
//
// Created by etsugo on 12/02/2022.
//
Ground::Ground(SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
}

Ground::~Ground() {
  std::vector<Character>::size_type size = characters.size();
  for (int i = 0; i < size; ++i) {
    delete &characters[i];//TODO smart pointer
  }
}

void Ground::update() {
  // Fill the surfaces to reset image
  const auto rect = SDL_Rect{0,0, frame_width, frame_height};
  auto color = SDL_MapRGB(this->window_surface_ptr_->format,10,255,10);
  SDL_FillRect(this->window_surface_ptr_, &rect, color);

  //foreach Character -> Character.onNewTik => reset les proximity a INT_MAX, decremente le temps du sex
  //Ordre : berger, chien, moutons, loups

  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0;i<size;++i){
    characters[i].move();
    draw(characters[i]);
  }
}

std::optional<Position> Ground::getNearDogPosition(Position fromPosition)
{
  float distance_from_dog = this->dog->getDistanceFrom(fromPosition);
  if(distance_from_dog<=WOLF_DISTANCE_FROM_DOG){
    return this->dog->getCenter();
  }
  return std::nullopt;
}

std::optional<Position>
Ground::getNearestSheepPosition(Position fromPosition, int ID)
{
  std::optional<Position> sheepToEatPosition = std::nullopt;

  float lastDistance = std::numeric_limits<float>::max();

  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0;i<size;++i){
    if (dynamic_cast<Sheep*>(&characters[i]) && characters[i].ID != ID)
    {
      float distance_current_sheep  = characters[i].getDistanceFrom(fromPosition);
      if(distance_current_sheep <= lastDistance)
      {
        sheepToEatPosition = characters[i].getCenter();
        lastDistance = distance_current_sheep;
      }
    }
  }

  return sheepToEatPosition;
}

bool Ground::canEat(Position fromPosition) {

  bool eat = false;

  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0;i<size;++i){
    if (dynamic_cast<Sheep*>(&characters[i]))
    {
      float distance_current_sheep  = characters[i].getDistanceFrom(fromPosition);
      if(distance_current_sheep <= DISTANCE_TO_EAT_SHEEP)
      {
        characters.erase(characters.begin() + i);
      }
    }
  }

  return eat;
}

void Ground::wolfIsHungry(int id)
{
  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0;i<size;++i){
    if (dynamic_cast<Wolf*>(&characters[i]))
    {
      if(characters[i].ID == id)
      {
        characters.erase(characters.begin() + i);
      }
    }
  }
}

std::optional<Position> Ground::getWolfToRunAway(Position fromPosition)
{
  std::optional<Position> wolfToRunPosition = std::nullopt;
  float distance_last_wolf  = std::numeric_limits<float>::max();

  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0;i<size;++i){
    if (dynamic_cast<Wolf*>(&characters[i]))
    {
      float distance_current_wolf  = characters[i].getDistanceFrom(fromPosition);
      if(distance_current_wolf <= SHEEP_PROXIMITY_RUN_AWAY){
        if(distance_current_wolf < distance_last_wolf)
        {
          distance_last_wolf = distance_current_wolf;
          wolfToRunPosition = characters[i].getCenter();
        }
      }
    }
  }
  return wolfToRunPosition;
}

bool Ground::findSheepMalePartner(Position fromPosition) {
  bool findPartner = false;
  std::vector<Character>::size_type size = characters.size();
  for(std::vector<Character>::size_type i=0; (i<size && !findPartner); ++i){
    if (dynamic_cast<Sheep*>(&characters[i]) && Male == dynamic_cast<Sheep*>(&characters[i])->sex)
    {
      findPartner = true;
    }
  }
  return findPartner;
}

void Ground::sheepHavingBaby(Position position)
{
  auto babySheep = Sheep(newID(), newSheepImage(), this, position, this);
  add_character(babySheep);
}


void Ground::add_character(Character character) {
  if (dynamic_cast<Sheperd_dog*>(&character))
  {
    playable_sheperd = dynamic_cast<Sheperd*>(&character);
  }
  else if (dynamic_cast<Sheperd_dog*>(&character))
  {
    dog = dynamic_cast<Sheperd_dog*>(&character);
  }
  characters.push_back(character);
}
void Ground::draw(Character character) {
  auto destRect = SDL_Rect{static_cast<int>(character.corner.x_pos),static_cast<int>(character.corner.y_pos), character.width, character.height}; //TODO w and h of png surface
  int result = SDL_BlitScaled(character.image_ptr_, NULL, this->window_surface_ptr_, &destRect);
  if (result < 0) {
    throw std::runtime_error("draw(): SBlitScaled FAiled "
                             "SDL_BitScaled Error: " +
                             std::string(SDL_GetError()));
  }
}
