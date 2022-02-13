// SDL_Test.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_keyboard.h>
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


typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int up;
  int down;
  int left;
  int right;
}app;













