//
// Created by etsugo on 13/02/2022.
//

#include <SDL_surface.h>
#include "wolf.h"
//"../../media/wolf.png"
wolf::wolf(SDL_Surface* image,
           class killObserver killObserver,
           class hungryObserver hungryObserver)
    : animal(image, 1) {
  this->killObserver = killObserver;
  this->hungryObserver = hungryObserver;
}

void wolf::move()
{
  if (isHungry())
  {
    return;
  }
  if (auto sheperd_dog = this->dog_2_run_away)
  {
    this->setDirectionToOpoPosition(sheperd_dog.getCenter());
  }
  else if (auto sheep = this->sheepToEat)
  {
    this->setDirectionToPosition(sheep.getCenter());
  }
  else
  {
    x_dir = 0;
    y_dir = 0;
  }

  float x_pos_temp = this->corner.x_pos + x_dir;
  float y_pos_temp = this->corner.y_pos + y_dir;

  if(y_pos_temp >= max_y)
  {
    y_pos_temp = max_y;
  }
  else if (y_pos_temp <= min_y)
  {
    y_pos_temp = min_y;
  }
  if(x_pos_temp >= max_x)
  {
    x_pos_temp = max_x;
  }
  else if (x_pos_temp <= min_x)
  {
    x_pos_temp = min_x;
  }

  this->corner.y_pos = y_pos_temp;
  this->corner.x_pos = x_pos_temp;

  if (auto sheep = this->sheepToEat)
  {
    if (this->getDistanceFrom(sheepToEat.getCenter()))
    {
      killObserver.sheepHaveBeenEat(sheepToEat);
    }
  }

}
bool wolf::isHungry() {
  timeLeft -= 1;
  if (0 >= timeLeft)
  {
    this->hungryObserver.wolfIsHungry(this);
  }
}
