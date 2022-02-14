//
// Created by etsugo on 13/02/2022.
//
#include <random>
#include "Sheep.h"

Sheep::Sheep(int ID,
             SDL_Surface* image,
             GroundUtils* groundUtils,
             SheepObserver* sheepObserver)
:Character(ID, image, SHEEP_VELOCITY, groundUtils)
{
  auto gen = std::bind(std::uniform_int_distribution<int>(0,1),std::default_random_engine());
  this->sex = gen() ? Male : Female;
  this->sheepObserver = sheepObserver;
  this->onBoost = false;
}

Sheep::Sheep(int ID,
             SDL_Surface* image,
             GroundUtils* groundUtils,
             Position position,
             SheepObserver* sheepObserver)
:Character(ID, image, SHEEP_VELOCITY, groundUtils, position)
{
  auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
  this->sex = gen() ? Male : Female;
  this->sheepObserver = sheepObserver;
  this->onBoost = false;
}
void Sheep::testSex()
{
  if (Female == this->sex && hungryTime == 0)
  {
    if (groundUtils->findSheepMalePartner(this->getCenter()))
    {
      sheepObserver->sheepHavingBaby(this->corner);
      hungryTime = timeBeforeNewBaby;
    }
  }
}

void Sheep::move() {

  if (auto wolfPosition = groundUtils->getWolfToRunAway(this->getCenter()))
  {
    if (!onBoost)
    {
      onBoost = true;
      this->velocity *= SHEEP_BOOST;
    }
    this->setPositionToOpoDirection(*wolfPosition);
  }
  else
  {
    if (onBoost)
    {
      onBoost = false;
      this->velocity /= SHEEP_BOOST;
    }
    this->setPositionToDirection(getRandomPosition());
  }

  Character::move();

  testSex();
}
