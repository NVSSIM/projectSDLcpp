//
// Created by 33668 on 14/02/2022.
//
#include "RandomPosition.h"
RandomPosition::RandomPosition(float minX, float maxX, float minY, float maxY)
{
    randomX = std::uniform_real_distribution<float>(minX, maxX);//,std::default_random_engine());
    randomY = std::uniform_real_distribution<float>(minY,maxY);
}
