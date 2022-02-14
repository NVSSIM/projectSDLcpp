//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEEP_H
#define PROJECT_SDL1_SHEEP_H

#include "Character.h"
#include "SheepObserver.h"
#include "RandomPosition.h"
class Sheep : public Character {
private:
    RandomPosition randomPosition;
public:
  Sex sex;
  int hungryTime = 0;
  bool onBoost = false;
  SheepObserver* sheepObserver;

  Sheep(
      int ID,
      SDL_Surface* image,
      GroundUtils* groundUtils,
      Position position,
      SheepObserver* sheepObserver,
      RandomPosition randomPosition
  );

  void move() override;
  void testSex();
};

#endif // PROJECT_SDL1_SHEEP_H
