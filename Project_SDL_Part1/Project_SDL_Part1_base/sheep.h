//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEEP_H
#define PROJECT_SDL1_SHEEP_H

#include "wolf.h"
#include "Observer.h"
static const float SHEEP_VELOCITY = 1;
constexpr float SHEEP_BOOST = 1.2;
constexpr int timeBeforeNewBaby= 10;
class sheep : public character
{
public:

  Sex sex;
  int hungryTime = 0;
  std::optional<wolf> wolfToRunAway = std::nullopt;
  bool onBoost;
  sexObserver sexObserver;

  //sheep(const std::string& filePath, SDL_Surface* windowSurfacePtr, Sex sex);
  sheep(SDL_Surface* imagePtr,
        Sex sex,
        sexObserver sexObserver);
  void move() override;
  void testSex();
};

#endif // PROJECT_SDL1_SHEEP_H
