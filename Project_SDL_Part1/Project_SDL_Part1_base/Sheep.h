//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEEP_H
#define PROJECT_SDL1_SHEEP_H

#include "Character.h"
#include "SheepObserver.h"

class Sheep : public Character {
public:
  Sex sex;
  int hungryTime = 0;
  bool onBoost = false;
  SheepObserver* sheepObserver;

  Sheep(
      int ID,
      SDL_Surface* image,
      GroundUtils* groundUtils,
      SheepObserver* sheepObserver
      );

  Sheep(
      int ID,
      SDL_Surface* image,
      GroundUtils* groundUtils,
      Position position,
      SheepObserver* sheepObserver
  );

  void move() override;
  void testSex();
};

#endif // PROJECT_SDL1_SHEEP_H
