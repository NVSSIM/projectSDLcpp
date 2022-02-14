//
// Created by 33668 on 12/02/2022.
//

#ifndef PROJECT_SDL1_GROUND_H
#define PROJECT_SDL1_GROUND_H
#include <vector>
#include <SDL.h>
#include "Character.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Sheperd_dog.h"
#include "Sheperd.h"
#include "SheepObserver.h"

class Ground : public GroundUtils, public SheepObserver, public WolfObserver {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

public:

  std::vector<std::shared_ptr<Character>> characters;
  Sheperd_dog *dog;

  Ground(SDL_Surface* window_surface_ptr);
  ~Ground();

  void update();
  // Possibly other methods, depends on your implementation
  void add_character(const std::shared_ptr<Character> character);

 // void add_character(Wolf character);
  //void add_character(Sheep character);
  //void add_character(Sheperd_dog character);
  //void add_character(Sheperd character);

  std::optional<Position> getNearDogPosition(Position fromPosition) override;
  std::optional<Position> getNearestSheepPosition(Position fromPosition, int ID) override;
  std::optional<Position> getWolfToRunAway(Position fromPosition) override;
  bool findSheepMalePartner(Position fromPosition) override;

  void sheepHavingBaby(Position position) override;
  void wolfIsHungry(int id) override;
  bool canEat(Position fromPosition) override;
  void draw(Character& character);

    Position getRandomPosition();
};
#endif // PROJECT_SDL1_GROUND_H
