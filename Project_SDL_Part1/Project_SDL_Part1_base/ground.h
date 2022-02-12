//
// Created by 33668 on 12/02/2022.
//

#ifndef PROJECT_SDL1_GROUND_H
#define PROJECT_SDL1_GROUND_H
class ground {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  std::vector<sheep*> sheeps;
  std::vector<wolf*> wolfs;
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
  void scanSWProximity();
  void sheepHavingSex();
};
#endif // PROJECT_SDL1_GROUND_H
