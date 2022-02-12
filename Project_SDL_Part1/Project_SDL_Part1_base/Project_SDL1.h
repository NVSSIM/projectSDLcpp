// SDL_Test.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>


// Defintions
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;
constexpr float SHEEP_PROXIMITY_TO_HAVE_SEX = 10;
constexpr float SHEEP_PROXIMITY_RUN_AWAY = 150;
constexpr float WOLF_DISTANCE_FROM_DOG = 10;
constexpr float SHEPERD_VELOCITY=4;
// Helper function to initialize SDL
void init();

class position
{
public:
  float x_pos = 0;
  float y_pos = 0;
  position(float x_pos, float y_pos);
};
class character{
private:

protected:
  int width;
  int height;

  int min_x = frame_boundary;
  int min_y = frame_boundary;
  int max_x = frame_width - frame_boundary - this->width;
  int max_y = frame_height - frame_boundary - this->height;

  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                                    // load_surface_for

public:
  position position;
  int x_pos = 0;
  int y_pos = 0;
  int x_dir = 1;
  int y_dir = 1;

  character(const std::string& file_path, SDL_Surface* window_surface_ptr);
  character(SDL_Surface* windowSurfacePtr);
  ~character();
  void draw();
  float getProximity(character character1);
  void move();

  SDL_Rect getDestRect();
  void draw(SDL_Surface* surface);
};

class animal : public character {
  void move();
};

class sheperd : public character {

public:
  sheperd(const std::string& filePath, SDL_Surface* windowSurfacePtr);
  sheperd(SDL_Surface* windowSurfacePtr);
  ~sheperd();
  virtual void move() override;
  void draw();


};
typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int up;
  int down;
  int left;
  int right;
}app;

enum Sex {
  Male,
  Female
};

class sheperd_dog : public character{
public:
  sheperd_dog(const std::string& filePath, SDL_Surface* windowSurfacePtr);
  sheperd_dog(SDL_Surface* windowSurfacePtr);
  ~sheperd_dog();
  void move() override;
  void draw();
  float getProximity(character character1);
};

int constexpr timeHaveHungry = 10;

class sheep : public animal {
public:

  Sex sex;
  int hungryTime = 0;
  wolf wolfToRunAway;
  bool onBoost;

  sheep(const std::string& filePath, SDL_Surface* windowSurfacePtr, Sex sex);
  sheep(SDL_Surface* windowSurfacePtr);
  ~sheep();
  void move() override;
  void draw();
  float getProximity(character character1);

};

// Insert here:
class wolf : public animal {
public:
  sheep sheepToEat;
  float sheepToEatDistance;
  sheperd_dog dog_2_run_away;
  wolf(const std::string& filePath, SDL_Surface* windowSurfacePtr);
  wolf(SDL_Surface* windowSurfacePtr);
  // Dtor
  ~wolf();
  // implement functions that are purely virtual in base class
  virtual void move() override;
  void draw();
  float getProximity(character character1);
};





