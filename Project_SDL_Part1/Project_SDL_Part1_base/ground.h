//
// Created by 33668 on 12/02/2022.
//

#ifndef PROJECT_SDL1_GROUND_H
#define PROJECT_SDL1_GROUND_H
#include <vector>
#include <SDL.h>
#include "Observer.h"
#include "sheep.h"
#include "wolf.h"
#include "sheperd_dog.h"
#include "sheperd.h"

class ground : public sexObserver, public killObserver, public hungryObserver
{
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  std::vector<sheep> sheeps;
  std::vector<wolf> wolfs;
  sheperd playable_sheperd;
  sheperd_dog dog;

public:
  ground(SDL_Surface* window_surface_ptr);
  ~ground();

  void update();
  // Possibly other methods, depends on your implementation
  void add_character(wolf character);
  void add_character(sheep character);
  void add_character(sheperd_dog character);
  void add_character(sheperd character);
  void sheepHavingBaby(sheep sheep) override;
  void sheepHaveBeenEat(sheep sheep) override;
  void wolfIsHungry(wolf wolf) override;
  void remove_character(wolf wolf1);
  void remove_character(sheep sheep);
  std::vector<sheep> getSheeps() override;
};
#endif // PROJECT_SDL1_GROUND_H
