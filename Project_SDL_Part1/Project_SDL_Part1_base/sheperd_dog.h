//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEPERD_DOG_H
#define PROJECT_SDL1_SHEPERD_DOG_H

class sheperd_dog : public character{
public:
  sheperd_dog(const std::string& filePath, SDL_Surface* windowSurfacePtr);
  sheperd_dog(SDL_Surface* windowSurfacePtr);
  ~sheperd_dog();
  void move() override;
  void draw();
  float getProximity(character character1);
};

#endif // PROJECT_SDL1_SHEPERD_DOG_H
