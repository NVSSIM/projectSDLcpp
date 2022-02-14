//
// Created by etsugo on 13/02/2022.
//

#include "Sheperd_dog.h"


Sheperd_dog::Sheperd_dog(int ID, SDL_Surface* image_ptr_,
                         GroundUtils* groundUtils, std::shared_ptr<Sheperd>& pSheperd,Position position)
    : Character(ID, image_ptr_, 1, groundUtils,position){
      sheperd = pSheperd;
      };

void Sheperd_dog::move(){

    auto shep = sheperd.get();
    float centerPosX = float(shep->getCenterX() - width) / 2 + shep->width * cos(SDL_GetTicks() / 580) ;//le centre
    float centerPosY = float(shep->getCenterY() - height) / 2 + shep->height * cos(SDL_GetTicks() / 580) ;
    this->setCenterX(centerPosX);
    this->setCenterY(centerPosY);

    Character::move();

}

