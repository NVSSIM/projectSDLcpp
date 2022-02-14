//
// Created by etsugo on 13/02/2022.
//


#ifndef PROJECT_SDL1_WOLF_H
#define PROJECT_SDL1_WOLF_H

#include <SDL_surface.h>
#include <optional>
#include "Character.h"
#include "WolfObserver.h"

class Wolf : public Character {
public:
  int timeLeft = timeBeforeHungry;
  WolfObserver* wolfObserver;

  Wolf(int id, SDL_Surface* imagePtr, GroundUtils* groundUtils,
       WolfObserver* wolfObserver,Position position);
  void move() override;
  void checkHungry();
};

#endif // PROJECT_SDL1_WOLF_H
