//
// Created by etsugo on 13/02/2022.
//

#include "Wolf.h"



Wolf::Wolf(int id, SDL_Surface* imagePtr,
           GroundUtils* groundUtils, WolfObserver* wolfObserver,Position position)
    : Character(id, imagePtr, WOLF_VELOCITY, groundUtils,position),
      wolfObserver(wolfObserver) {this->wolfObserver = wolfObserver;
  this->timeLeft = timeBeforeHungry;}

void Wolf::move()
{
  if (auto dogPosition = this->groundUtils->getNearDogPosition(getCenter()))
  {
    this->setPositionToOpoDirection(*dogPosition);
  }
  else if (auto sheepToEatPosition =
                 this->groundUtils->getNearestSheepPosition(getCenter(),
                                                           this->ID))
  {
    this->setPositionToDirection(*sheepToEatPosition);
  }

  Character::move();

  checkHungry();
}

void Wolf::checkHungry()
{
  if (wolfObserver->canEat(getCenter()))
  {
    timeLeft = timeBeforeHungry;
  }
  else
  {
    timeLeft -= 1;
    if (0 >= timeLeft)
    {
      this->wolfObserver->wolfIsHungry(ID);
    }
  }
}
