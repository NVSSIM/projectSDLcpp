// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>
#include <SDL_keyboard.h>

#include "application.h"
#include "ground.h"

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {

  SDL_Surface* sdlSurfaceLoad = IMG_Load(path.c_str());
  if (!sdlSurfaceLoad) {
    throw std::runtime_error("load_surface_for(): SDL_Surface could not load! "
                             "IMG_Load Error: " +
                             std::string(IMG_GetError()));
  }

  SDL_Surface* sdlSurface =
      SDL_ConvertSurface(sdlSurfaceLoad, window_surface_ptr->format, 0);
  if (!sdlSurface) {
    throw std::runtime_error("load_surface_for(): SDL_Surface could not load! "
                             "IMG_Load Error: " +
                             std::string(SDL_GetError()));
  }

  return sdlSurface;
}
} // namespace

application::application(unsigned int n_sheep, unsigned int n_wolf) {

  this->n_wolf = n_wolf;
  this->n_sheep = n_sheep;

  SDL_Window* sdlWindow = SDL_CreateWindow(
      "Moutons SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      frame_width, frame_height, SDL_WINDOW_OPENGL);
  this->window_ptr_ = sdlWindow;

  SDL_Surface* sdlSurface = SDL_GetWindowSurface(sdlWindow);
  this->window_surface_ptr_ = sdlSurface;

  //adding character
  for (int i = 0; i < n_sheep; ++i) {
    auto csheep = sheep(this->window_surface_ptr_);
    this->app_grnd->add_character(csheep);
  }
  for (int i = 0; i < n_wolf; ++i)
  {
    auto cwolf = wolf(this->window_surface_ptr_);
    this->app_grnd->add_character(cwolf);
  }
  auto cdog = sheperd_dog(this->window_surface_ptr_);
  this->app_grnd->add_character(cdog);

}



application::~application() { SDL_DestroyWindow(this->window_ptr_); }
int application::loop(unsigned int period) {

  while (SDL_GetTicks() < 1000) {
    this->app_grnd->update();
    SDL_UpdateWindowSurface(this->window_ptr_);
    SDL_Delay(frame_time* 1000);
  }
  return 0;
}

ground::ground(SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
}

ground::~ground() {
  for (int i = 0; i < character.size(); ++i) {
    delete character[i];
  }
}

void ground::add_character(wolf character)
{
  this->wolfs.push_back(&character);
}
void ground::add_character(sheep character)
{
  this->sheeps.push_back(&character);
}
void ground::add_character(sheperd_dog character)
{
  this->dog = character;
}
void ground::add_character(sheperd character)
{
  this->playable_sheperd = character;
}

float character::getProximity(character character1) {
  float x_pow = pow(this->x_pos - character1.x_pos, 2);
  float y_pow = pow(this->y_pos - character1.y_pos, 2);
  return sqrtf(x_pow + y_pow);
}

void ground::update() {
  // Fill the surfaces to reset image
  const auto rect = SDL_Rect{0,0, frame_width, frame_height};
  auto color = SDL_MapRGB(this->window_surface_ptr_->format,10,255,10);
  SDL_FillRect(this->window_surface_ptr_, &rect, color);

  //foreach character -> character.onNewTik => reset les proximity a INT_MAX, decremente le temps du sex
  //Ordre : berger, chien, moutons, loups
  for (auto *canimal: this->sheeps)
  {
    canimal->move();
    canimal->draw();
  }
  for (auto *canimal: this->wolfs)
  {
    canimal->move();
    canimal->draw();
  }

}

character::character(const std::string& file_path, SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
  this->image_ptr_ = load_surface_for(file_path, window_surface_ptr);

  this->width = this->image_ptr_->w;
  this->height = this->image_ptr_->h;

  //todo: use random lib
  this->y_pos = (rand() % (frame_height - this->height-2*frame_boundary))+frame_boundary;
  this->x_pos = (rand() % (frame_width - this->width -2*frame_boundary))+frame_boundary;

  this->x_dir = rand() % 10; //10 est la vitesse
  this->y_dir = 10 - this->x_dir;
}
animal::~animal() { SDL_FreeSurface(this->image_ptr_);
}

SDL_Rect character::getDestRect()
{
  return SDL_Rect{this->x_pos,this->y_pos, this->width, this->height};
}
void character::draw(SDL_Surface* surface) {
  auto destRect = SDL_Rect{this->x_pos,this->y_pos, this->width, this->height}; //TODO w and h of png surface
  int result = SDL_BlitScaled(this->image_ptr_, NULL, surface, &destRect);
  if (result < 0) {
    throw std::runtime_error("draw(): SBlitScaled FAiled "
                             "SDL_BitScaled Error: " +
                             std::string(SDL_GetError()));
  }
}


void ground::sheperd_dog_fear(wolf wolf){
  float distance_from_dog = dog.getProximity(wolf);
  if(distance_from_dog<=WOLF_DISTANCE_FROM_DOG){
    wolf.dog_2_run_away = dog;
  }
}
void ground::setRunAwayAndEat(sheep sheep)
{
    wolf nearestWolf = NULL;
    float distance_last_wolf  = INT_MAX;

    float x_sheep = sheep.x_pos;
    float y_sheep = sheep.y_pos;
    //check des loup
    for(auto wolf : this->wolfs)
    {
      float distance_current_wolf  = sheep.getProximity(wolf);

      if(distance_current_wolf <= SHEEP_PROXIMITY_RUN_AWAY){
        if(distance_current_wolf <= wolf->sheepToEatDistance){
          wolf->sheepToEat = sheep;
          wolf->sheepToEatDistance = distance_current_wolf;
        }
        if(distance_current_wolf < distance_last_wolf){
          distance_last_wolf = distance_current_wolf;
        }
        nearestWolf = wolf;
      }

    }
    //Faire pareil avec le chien
    // if distance_dog <= SHEEP_PROXIMITY_RUN_AWAY
    //wolf est le loup le plus pret, si il n'y en a pas, null;
    sheep.wolfToRunAway = nearestWolf;


}

void ground::setMakeSex(sheep sheep)
{
  if (Female == sheep.sex)
  {
    for (auto sheep2 : this->sheeps)
    {
      if (Male == sheep.sex)
      {
        if (sheep.getProximity(sheep2) <= SHEEP_PROXIMITY_TO_HAVE_SEX)
        {
          this->sheepHavingSex(sheep);
        }
      }
    }
  }
}
void ground::sheepHavingSex(sheep sheep)
{
  sheep.hungryTime = timeHaveHungry;
  add_character(sheep);
}

sheep::sheep(SDL_Surface* windowSurfacePtr)
    : animal("../../media/sheep.png", windowSurfacePtr) {}
sheep::~sheep() {}

void sheep::setDir()
{
  if (NULL != this->wolfToRunAway)
  {
    if (!onBoost)
    {
      onBoost = true;
      this->y_dir = this->wolfToRunAway->y_dir * SHEEP_BOOST;
      this->x_dir = this->wolfToRunAway->x_dir * SHEEP_BOOST;
    }
    else
    {
      this->y_dir = this->wolfToRunAway->y_dir;
      this->x_dir = this->wolfToRunAway->x_dir;
    }
  }
  else
  {
    if (onBoost)
    {
      onBoost = false;
      this->y_dir = this->y_dir / SHEEP_BOOST;
      this->x_dir = this->x_dir / SHEEP_BOOST;
    }
    else
    {
      this->y_dir = this->y_dir;
      this->x_dir = this->x_dir;
    }
  }
}

 void animal::move() {

  int x_pos_temp = x_pos + x_dir;
  int y_pos_temp = y_pos + y_dir;

  if(y_pos_temp >= max_y || y_pos_temp <= min_y){
    this->y_dir *= -1;
    y_pos_temp = y_pos + y_dir;
  }

  if(x_pos_temp >= max_x || x_pos_temp <= min_x){
    this->x_dir *= -1 ;
    x_pos_temp = x_pos + x_dir;
  }

  this->x_pos = x_pos_temp;
  this->y_pos = y_pos_temp;
}

wolf::wolf(SDL_Surface* windowSurfacePtr)
    : animal("../../media/wolf.png", windowSurfacePtr) {}
wolf::~wolf(){}

void wolf::setDir()
{
    float dirX = this->getXDirToAnimal(this->sheepToEat);
    float x_pos_temp = this->x_pos + dirX;

    float dirY = this->getYDirToAnimal(this->sheepToEat);
    float y_pos_temp = this->y_pos + dirY;

    if(
        (x_pos_temp /*droite*/ >= this->dog_2_run_away.x_pos/*gauche*/ && x_pos_temp/*gauche*/ <= this->dog_2_run_away.x_pos/*droite*/)
        && (y_pos_temp/*bas*/ >= this->dog_2_run_away.y_pos/*haut*/ && y_pos_temp/*haut*/ <= this->dog_2_run_away.y_pos/*bas*/)
        )//TODO add proximity
    {
      if (dog_2_run_away.x_dir < 0 && dirX > 0)
      {
        x_pos_temp = dog_2_run_away.x_pos/*droite*/;
      }
      else if (dog_2_run_away.x_dir > 0 && dirX < 0)
      {
        x_pos_temp = dog_2_run_away.x_pos/*gauche*/;
      }

      if (dog_2_run_away.y_dir < 0 && dirY > 0)
      {
        y_pos_temp = dog_2_run_away.y_pos/*droite*/;
      }
      else if (dog_2_run_away.y_dir > 0 && dirY < 0)
      {
        y_pos_temp = dog_2_run_away.y_pos/*gauche*/;
      }
    }

    x_pos = x_pos_temp;
    y_pos = y_pos_temp;
}

float animal::getYDirToAnimal(animal animal, float velocity)
{
  float dirY = 0;
  if (NULL != animal)
  {
    float distance = this->getProximity(animal);
    float sinf = (animal.y_pos - this->y_pos) / distance;
    dirY = velocity * sinf;
  }
  return dirY;
}

float animal::getXDirToAnimal(animal animal, float velocity)
{
  float dirX = 0;
  if (NULL != animal)
  {
    float distance = this->getProximity(animal);
    float cosf = (animal.x_pos - this->x_pos) / distance;
    dirX = velocity * cosf;
  }
  return dirX;
}

void wolf::move() {

  int x_pos_temp = x_pos + x_dir;
  int y_pos_temp = y_pos + y_dir;

  int min_x = frame_boundary;
  int min_y = frame_boundary;
  int max_x = frame_width - frame_boundary - this->width;
  int max_y = frame_height - frame_boundary - this->height;

  if(x_pos_temp >= max_x || x_pos_temp <= min_x){
    this->x_dir *= -1 ; // J'inverse la direction
    x_pos_temp = x_pos + x_dir;
  }

  if(y_pos_temp >= max_y || y_pos_temp <= min_y){
    this->y_dir *= -1;
    y_pos_temp = y_pos + y_dir;
  }

  this->x_pos = x_pos_temp;
  this->y_pos = y_pos_temp;
}
void sheperd::move(){
  const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
  if(keyboard_state_array[SDL_SCANCODE_Z]){
    this->y_pos += SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_S]){
    this->y_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_Q]){
    this->x_pos -= SHEPERD_VELOCITY;
  }
  if(keyboard_state_array[SDL_SCANCODE_D]){
    this->x_pos += SHEPERD_VELOCITY;
  }
  if(this->x_pos<0){
    this->x_pos=0;
  }
  if(this->y_pos<0){
    this->y_pos=0;
  }
}





