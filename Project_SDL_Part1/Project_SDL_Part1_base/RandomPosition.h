//
// Created by 33668 on 14/02/2022.
//

#ifndef PROJECT_SDL1_RADOMPOSITION_H
#define PROJECT_SDL1_RADOMPOSITION_H

#include <random>
#include <functional>
#include "Position.h"

class RandomPosition {
private:
    std::default_random_engine generator;
    std::uniform_real_distribution<float> randomX;//,std::default_random_engine());
    std::uniform_real_distribution<float> randomY;
public:
    RandomPosition(float minX, float maxX, float minY, float maxY);
    Position getRandomPosition();
};


#endif //PROJECT_SDL1_RADOMPOSITION_H
