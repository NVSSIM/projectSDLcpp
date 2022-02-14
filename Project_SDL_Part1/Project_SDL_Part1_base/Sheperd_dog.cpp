//
// Created by etsugo on 13/02/2022.
//

#include "Sheperd_dog.h"

Sheperd_dog::Sheperd_dog(int ID, SDL_Surface* image_ptr_,
                         GroundUtils* groundUtils, Sheperd* pSheperd)
    : Character(ID, image_ptr_, 1, groundUtils){
      sheperd = pSheperd;
      };

void Sheperd_dog::move(){

    float centerPosX = float(sheperd->getCenterX() - width) / 2 + sheperd->width * cos(SDL_GetTicks() / 580) ;//le centre
    float centerPosY = float(sheperd->getCenterY() - height) / 2 + sheperd->height * cos(SDL_GetTicks() / 580) ;
    this->setCenterX(centerPosX);
    this->setCenterY(centerPosY);

    Character::move();

}

