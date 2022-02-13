//
// Created by etsugo on 12/02/2022.
//

#ifndef PROJECT_SDL1_CHARACTER_H
#define PROJECT_SDL1_CHARACTER_H

#include "position.h"
#include "Project_SDL1.h"

enum Sex {
  Male,
  Female
};

class character {

private:

protected:

  int width;
  int height;

  float min_x = frame_boundary;
  float min_y = frame_boundary;
  float max_x = frame_width - frame_boundary - this->width;
  float max_y = frame_height - frame_boundary - this->height;

  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                                    // load_surface_for

public:
  float velocity{};
  position corner = position(0, 0);
  float x_dir;
  float y_dir;

  character(SDL_Surface* image_ptr_,float velocity);
  //character(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~character();

  virtual void move(){}
  void draw(SDL_Surface* surface);//void draw(); TODO move to ground

  float getDistanceFrom(position position);
  void setDirectionToPosition(position position);
  position getCenter();
  float getCenterX();
  float getCenterY();
  void setDirectionToOpoPosition(position position);
};

#endif // PROJECT_SDL1_CHARACTER_H
