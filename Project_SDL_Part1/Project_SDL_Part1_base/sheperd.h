//
// Created by etsugo on 13/02/2022.
//

#ifndef PROJECT_SDL1_SHEPERD_H
#define PROJECT_SDL1_SHEPERD_H

class sheperd : public character {

public:
  sheperd(const std::string& filePath, SDL_Surface* windowSurfacePtr);
  sheperd(SDL_Surface* windowSurfacePtr);
  ~sheperd();
  virtual void move() override;
  void draw();


};

#endif // PROJECT_SDL1_SHEPERD_H
