//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEPERD_H
#define PROJECT_SDL1_SHEPERD_H

#include <SDL_surface.h>
#include "Character.h"
class Sheperd : public Character {

public:
  Sheperd(int ID,
            SDL_Surface* image_ptr_,
            GroundUtils* groundUtils);
  void move() override;
};

#endif // PROJECT_SDL1_SHEPERD_H
