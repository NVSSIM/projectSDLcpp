//
// Created by 33668 on 12/02/2022.
//

#ifndef PROJECT_SDL1_APPLICATION_H
#define PROJECT_SDL1_APPLICATION_H
#include "Ground.h"
// The application class, which is in charge of generating the window
class application {
private:
  // The following are OWNING ptrs
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;
  unsigned int n_wolf;
  unsigned int n_sheep;
  Ground* app_grnd;
  // Other attributes here, for example an instance of Ground

public:
  application(unsigned n_sheep, unsigned n_wolf); // Ctor
  ~application();                                 // dtor

  int loop(unsigned period);
};
#endif // PROJECT_SDL1_APPLICATION_H
