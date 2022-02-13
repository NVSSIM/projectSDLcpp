//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_WOLF_H
#define PROJECT_SDL1_WOLF_H

#include "sheep.h"

constexpr int timeBeforeHungry = 20;
class wolf : public character
{
public:
  std::optional<sheep> sheepToEat = std::nullopt;
  std::optional<sheperd_dog> dog_2_run_away = std::nullopt;
  int timeLeft = timeBeforeHungry;

  killObserver killObserver;
  hungryObserver hungryObserver;

  wolf(
       SDL_Surface* image,
       killObserver killObserver,
       hungryObserver hungryObserver);

  void move() override;
  bool isHungry();
};

#endif // PROJECT_SDL1_WOLF_H
