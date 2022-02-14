//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_WOLFOBSERVER_H
#define PROJECT_SDL1_WOLFOBSERVER_H

#include "Position.h"

class WolfObserver {
public:
  virtual void wolfIsHungry(int id) {};
  virtual bool canEat(Position fromPosition) {return false;};
};


#endif // PROJECT_SDL1_WOLFOBSERVER_H
