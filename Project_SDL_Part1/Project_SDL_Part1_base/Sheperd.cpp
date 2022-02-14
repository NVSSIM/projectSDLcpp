//
// Created by etsugo on 13/02/2022.
//

#include <SDL_scancode.h>
#include "Sheperd.h"
#include "Project_SDL1.h"

Sheperd::Sheperd(int ID, SDL_Surface* image_ptr_,
                 GroundUtils* groundUtils,Position position)
    : Character(ID, image_ptr_, 1, groundUtils,position) {}

void Sheperd::move(){
  const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
  if(keyboard_state_array[SDL_SCANCODE_Z]){
    this->corner.y_pos += SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_S]){
    this->corner.y_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_Q]){
    this->corner.x_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_D]){
    this->corner.x_pos += SHEPERD_VELOCITY;
  }

  Character::move();
}

