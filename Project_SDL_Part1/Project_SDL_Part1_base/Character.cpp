//
// Created by etsugo on 12/02/2022.
//

#include <random>
#include "Character.h"

Character::Character(
    int ID,
    SDL_Surface* image_ptr_,
    float velocity,
    GroundUtils* groundUtils,
    Position position)
{
  this->image_ptr_ = image_ptr_;
  this->ID = ID;

  this->groundUtils = groundUtils;

  this->width = this->image_ptr_->w;
  this->height = this->image_ptr_->h;
    this->max_x = frame_width - this->width;
    this->max_y = frame_height - this->height;

  this->velocity = velocity;

  this->corner = position;
}

Character::~Character()
{
  SDL_FreeSurface(this->image_ptr_);
  //TODO remove groundUtils
}

Position Character::getCenter() { return {getCenterX(),getCenterY()}; }
float Character::getCenterX() { return this->corner.x_pos + (float(this->width) / 2); }
float Character::getCenterY() { return this->corner.y_pos + (float(this->height) / 2); }
void Character::setCenterX(float centerX) { this->corner.x_pos = centerX - (float(this->width) /2);}
void Character::setCenterY(float centerY) { this->corner.y_pos = centerY - (float(this->height) /2); }

float Character::getDistanceFrom(Position position)
{
  float x_pow = powf(this->getCenterX() - position.x_pos, 2);
  float y_pow = powf(this->getCenterY() - position.y_pos, 2);
  return sqrtf(x_pow + y_pow);
}
void Character::setPositionToDirection(Position position) {
  float distance = this->getDistanceFrom(position);

  if (0 != distance)
  {
    float cosf = (position.x_pos - this->getCenterX()) / distance;
    float x_dir = velocity * cosf;
    this->corner.x_pos += x_dir;

    float sinf = (position.y_pos - this->getCenterY()) / distance;
    float y_dir = velocity * sinf;
    this->corner.y_pos += y_dir;
  }

}

void Character::setPositionToOpoDirection(Position position) {
  float distance = this->getDistanceFrom(position);
  if (0 != distance) {
    float cosf = (position.x_pos - this->getCenterX()) / distance;
    float x_dir = velocity * cosf * -1;
    this->corner.x_pos += x_dir;

    float sinf = (position.y_pos - this->getCenterY()) / distance;
    float y_dir = velocity * sinf * -1;
    this->corner.y_pos += y_dir;
  }
}

