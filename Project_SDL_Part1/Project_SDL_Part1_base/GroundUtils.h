//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_GROUNDUTILS_H
#define PROJECT_SDL1_GROUNDUTILS_H

#include "Position.h"

class GroundUtils {
public:
  virtual std::optional<Position> getNearDogPosition(Position fromPosition) {return std::nullopt;};
  virtual std::optional<Position> getNearestSheepPosition(Position fromPosition, int ID) {return std::nullopt;};
  virtual std::optional<Position> getWolfToRunAway(Position fromPosition) {return std::nullopt;};
  virtual bool findSheepMalePartner(Position fromPosition) {return false;};
};

#endif // PROJECT_SDL1_GROUNDUTILS_H
