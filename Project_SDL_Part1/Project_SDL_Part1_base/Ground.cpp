#include "Ground.h"

#include <iostream>
#include <utility>
#include <vector>
#include <SDL.h>
#include "Sheep.h"
#include "Project_SDL1.h"
#include "Sheperd.h"
#include "Sheperd_dog.h"
//
// Created by etsugo on 12/02/2022.
//
Ground::Ground(SDL_Surface* window_surface_ptr)
{
  this->window_surface_ptr_ = window_surface_ptr;
}

Ground::~Ground() {
    /*
  std::vector<Character>::size_type size = characters.size();
  for (int i = 0; i < size; ++i) {
    delete &characters[i];//TODO smart pointer
  }
     */
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
    characters[i].get()->move();
    draw(characters[i].operator*());
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

    std::vector<std::shared_ptr<Character>>::size_type size = characters.size();
  for(std::vector<std::shared_ptr<Character>>::size_type i=0;i<size;++i){

    if (auto castChar = dynamic_cast<Sheep*>(characters[i].get()))
    {
        if (characters[i]->ID != ID)
        {
            float distance_current_sheep  = castChar->getDistanceFrom(fromPosition);
            if(distance_current_sheep <= lastDistance)
            {
                sheepToEatPosition = castChar->getCenter();
                lastDistance = distance_current_sheep;
            }
        }
    }
  }

  return sheepToEatPosition;
}

bool Ground::canEat(Position fromPosition) {

  bool eat = false;

  std::vector<std::shared_ptr<Character>>::size_type size = characters.size();
  for(std::vector<std::shared_ptr<Character>>::size_type i=0;i<size;++i){
    if (auto castChar = dynamic_cast<Sheep*>(characters[i].get()))
    {
      float distance_current_sheep  = castChar->getDistanceFrom(fromPosition);
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
  std::vector<std::shared_ptr<Character>>::size_type size = characters.size();
  for(std::vector<std::shared_ptr<Character>>::size_type i=0;i<size;++i){
    if (auto castChar = dynamic_cast<Wolf*>(characters[i].get()))
    {
      if(castChar->ID == id)
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

  std::vector<std::shared_ptr<Character>>::size_type size = characters.size();
  for(std::vector<std::shared_ptr<Character>>::size_type i=0;i<size;++i){
    if (auto castChar = dynamic_cast<Wolf*>(characters[i].get()))
    {
      float distance_current_wolf  = castChar->getDistanceFrom(fromPosition);
      if(distance_current_wolf <= SHEEP_PROXIMITY_RUN_AWAY){
        if(distance_current_wolf < distance_last_wolf)
        {
          distance_last_wolf = distance_current_wolf;
          wolfToRunPosition = castChar->getCenter();
        }
      }
    }
  }
  return wolfToRunPosition;
}

bool Ground::findSheepMalePartner(Position fromPosition) {
  bool findPartner = false;
  std::vector<std::shared_ptr<Character>>::size_type size = characters.size();
  for(std::vector<std::shared_ptr<Character>>::size_type i=0; (i<size && !findPartner); ++i){
    if (auto castChar = dynamic_cast<Sheep*>(characters[i].get()))
    {
        if(castChar->getDistanceFrom(fromPosition) <= SHEEP_PROXIMITY_TO_HAVE_SEX){
            if (Male == castChar->sex){
                findPartner = true;
            }
        }
    }
  }
  return findPartner;
}

void Ground::sheepHavingBaby(Position position)
{
  add_character(std::make_shared<Sheep>(newID(),newSheepImage(window_surface_ptr_), this, position,this));
}

void Ground::add_character(const std::shared_ptr<Character> character) {

  if (auto castChar = dynamic_cast<Sheperd_dog*>(character.get()))
  {
    dog = castChar;
  }
  characters.push_back(character);
}
void Ground::draw(Character& character) {
    int x = character.corner.x_pos;
    int y = character.corner.y_pos;
    int w = character.width;
    int h = character.height;
  auto destRect = SDL_Rect{x,y, w, h}; //TODO w and h of png surface
  int result = SDL_BlitScaled(character.image_ptr_, NULL, this->window_surface_ptr_, &destRect);
  if (result < 0) {
    throw std::runtime_error("draw(): SBlitScaled FAiled "
                             "SDL_BitScaled Error: " +
                             std::string(SDL_GetError()));
  }
}
