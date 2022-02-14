//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEPERD_DOG_H
#define PROJECT_SDL1_SHEPERD_DOG_H

#include <SDL.h>
#include "Character.h"
#include "Sheperd.h"
class Sheperd_dog : public Character {
public:
  Sheperd_dog(int ID, SDL_Surface* image_ptr_, GroundUtils* groundUtils,
              Sheperd* pSheperd);
  void move() override;
  Sheperd* sheperd;
};

#endif // PROJECT_SDL1_SHEPERD_DOG_H
