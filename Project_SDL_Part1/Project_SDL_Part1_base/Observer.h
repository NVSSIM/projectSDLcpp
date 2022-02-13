//
// Created by etsugo on 13/02/2022.
//

#include "wolf.h"
class sexObserver {

public:
  virtual void sheepHavingBaby(sheep sheep1) {};
  virtual std::vector<sheep> getSheeps() {};
};

class killObserver
{
public:
  virtual void sheepHaveBeenEat(sheep sheep1) {};
};

class hungryObserver
{
public:
  virtual void wolfIsHungry(wolf wolf1) {};
};