//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEEPOBSERVER_H
#define PROJECT_SDL1_SHEEPOBSERVER_H

#include "Sheep.h"

class SheepObserver {
public:
  virtual void sheepHavingBaby(Position position) {};
};

#endif // PROJECT_SDL1_SHEEPOBSERVER_H
