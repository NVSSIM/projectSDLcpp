//
// Created by etsugo on 13/02/2022.
//

#include "sheep.h"
#include "wolf.h"
#include "Observer.h"
#include "character.h"

sheep::sheep(SDL_Surface* imagePtr,
             Sex sex,
             class sexObserver sexObserver)
    : animal(imagePtr, 1) {
  this->sex = sex;
  this->sexObserver = sexObserver;
}

void sheep::move() {

  if (auto wolf = this->wolfToRunAway)
  {
    if (!onBoost)
    {
      onBoost = true;
      this->velocity *= SHEEP_BOOST;
    }
    this->setDirectionToOpoPosition(wolf.getCenter());
  }
  else
  {
    if (onBoost)
    {
      onBoost = false;
      this->velocity /= SHEEP_BOOST;
      this->y_dir = this->y_dir / SHEEP_BOOST;
      this->x_dir = this->x_dir / SHEEP_BOOST;
    }
  }

  float x_pos_temp = corner.x_pos + x_dir;
  float y_pos_temp = corner.y_pos + y_dir;

  if(y_pos_temp >= max_y || y_pos_temp <= min_y){
    this->y_dir *= -1;
    y_pos_temp = corner.y_pos + y_dir;
  }

  if(x_pos_temp >= max_x || x_pos_temp <= min_x){
    this->x_dir *= -1 ;
    x_pos_temp = corner.x_pos + x_dir;
  }

  this->corner.x_pos = x_pos_temp;
  this->corner.y_pos = y_pos_temp;

  testSex();
}
void sheep::testSex()
{
  auto sheeps = sexObserver.getSheeps();
  if (Female == this->sex && hungryTime == 0)
  {
    for (auto& sheep2 : sheeps)
    {
      if (Male == sheep2.sex)
      {
        if (this->getDistanceFrom(sheep2.getCenter()) <= SHEEP_PROXIMITY_TO_HAVE_SEX)
        {
          sexObserver.sheepHavingBaby(*this);
          hungryTime = timeBeforeNewBaby;
        }
      }
    }
  }
}

