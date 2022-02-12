//
// Created by 33668 on 12/02/2022.
//

#ifndef PROJECT_SDL1_APPLICATION_H
#define PROJECT_SDL1_APPLICATION_H
// The application class, which is in charge of generating the window
class application {
private:
  // The following are OWNING ptrs
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;
  unsigned int n_wolf;
  unsigned int n_sheep;
  ground* app_grnd;
  // Other attributes here, for example an instance of ground

public:
  application(unsigned n_sheep, unsigned n_wolf); // Ctor
  ~application();                                 // dtor

  int loop(unsigned period);
};
#endif // PROJECT_SDL1_APPLICATION_H
