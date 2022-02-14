//
// Created by etsugo on 12/02/2022.
//

#ifndef PROJECT_SDL1_CHARACTER_H
#define PROJECT_SDL1_CHARACTER_H

#include <random>
#include <functional>
#include "Position.h"
#include "Project_SDL1.h"
#include "GroundUtils.h"

enum Sex {
  Male,
  Female
};

class Character {

private:

protected:
  float min_x = 0;// frame_boundary;
  float min_y = 0;//frame_boundary;
  float max_x = float(frame_width - this->width); //- frame_boundary
  float max_y = float(frame_height - this->height);//- frame_boundary


  std::default_random_engine generator;
  std::uniform_real_distribution<float> randomX;
  std::uniform_real_distribution<float> randomY;

  GroundUtils* groundUtils;
  // The texture of the Sheep (the loaded image), use
                                    // load_surface_for

public:
  float velocity{};
  Position corner = Position(0, 0);

  Character(int ID,
            SDL_Surface* image_ptr_,
            float velocity,
            GroundUtils* groundUtils,
            Position position);
  Character(int ID,
            SDL_Surface* image_ptr_,
            float velocity,
            GroundUtils* groundUtils);
  ~Character();

  virtual void move()
  {
    if(corner.y_pos >= max_y)
    {
      this->corner.y_pos = max_y;
    }
    else if (corner.y_pos <= min_y)
    {
      this->corner.y_pos = min_y;
    }
    if(corner.x_pos >= max_x)
    {
      this->corner.x_pos = max_x;
    }
    else if (corner.x_pos <= min_x)
    {
      this->corner.x_pos = min_x;
    }
  };

  float getDistanceFrom(Position position);
  void setPositionToDirection(Position position);
  Position getCenter();
  float getCenterX();
  float getCenterY();
  void setCenterX(float centerX);
  void setCenterY(float centerY);
  void setPositionToOpoDirection(Position position);
  int ID;

  Position getRandomPosition();
  int width;
  int height;
  SDL_Surface* image_ptr_;
};

#endif // PROJECT_SDL1_CHARACTER_H
