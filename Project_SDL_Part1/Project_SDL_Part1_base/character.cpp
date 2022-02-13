//
// Created by etsugo on 12/02/2022.
//

#include <random>
#include "character.h"

character::character(
    SDL_Surface* image_ptr_
    ,float velocity
    //const std::string& file_path,
    //                SDL_Surface* window_surface_ptr
                    )
{
  this->image_ptr_ = image_ptr_;//load_surface_for(file_path, window_surface_ptr);

  this->width = this->image_ptr_->w;
  this->height = this->image_ptr_->h;

  std::default_random_engine generator;
  std::uniform_real_distribution<float> distributionX(frame_boundary, float(frame_width - this->width) - 2 * frame_boundary);
  std::uniform_real_distribution<float> distributionY(frame_boundary, float(frame_height - this->height) - 2 * frame_boundary);

  //todo: use random lib
  float x_pos = distributionX(generator);
  float y_pos = distributionY(generator);

  this->corner = position(x_pos, y_pos);

  this->x_dir = 0;
  this->y_dir = 0;
}

character::~character()
{
  SDL_FreeSurface(this->image_ptr_);
}

position character::getCenter() { return {getCenterX(),getCenterY()}; }
float character::getCenterX() { return this->corner.x_pos + (float(this->width) / 2); }
float character::getCenterY() { return this->corner.y_pos + (float(this->height) / 2); }

float character::getDistanceFrom(position position)
{
  float x_pow = powf(this->getCenterX() - position.x_pos, 2);
  float y_pow = powf(this->getCenterY() - position.y_pos, 2);
  return sqrtf(x_pow + y_pow);
}
void character::setDirectionToPosition(position position) {
  float distance = this->getDistanceFrom(position);

  float cosf = (position.x_pos - this->getCenterX()) / distance;
  this->x_dir = velocity * cosf;

  float sinf = (position.y_pos - this->getCenterY()) / distance;
  this->y_dir = velocity * sinf;
}
void character::setDirectionToOpoPosition(position position) {
  float distance = this->getDistanceFrom(position);

  float cosf = (position.x_pos - this->getCenterX()) / distance;
  this->x_dir = velocity * cosf * -1;

  float sinf = (position.y_pos - this->getCenterY()) / distance;
  this->y_dir = velocity * sinf * -1;
}
