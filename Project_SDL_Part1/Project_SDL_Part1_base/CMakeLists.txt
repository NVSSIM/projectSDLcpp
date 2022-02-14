cmake_minimum_required (VERSION 3.0)
project ("Project_SDL_sub")


IF(WIN32)
  message(STATUS "Building for windows")

  set(SDL2_INCLUDE_DIR C:/Users/33668/source/repos/Project_SDL_Part1/Project_SDL_Part1_base/SDL2/include)
  set(SDL2_LIB_DIR C:/Users/33668/source/repos/Project_SDL_Part1/Project_SDL_Part1_base/SDL2/lib/x64)

  set(SDL2_IMG_INCLUDE_DIR C:/Users/33668/source/repos/Project_SDL_Part1/Project_SDL_Part1_base/SDL2_image/include)
  set(SDL2_IMG_LIB_DIR C:/Users/33668/source/repos/Project_SDL_Part1/Project_SDL_Part1_base/SDL2_image/lib/x64)


  # Support both 32 and 64 bit builds
  include_directories(${SDL2_INCLUDE_DIR})
  link_directories(${SDL2_LIB_DIR})

  include_directories(${SDL2_IMG_INCLUDE_DIR})
  link_directories(${SDL2_IMG_LIB_DIR})

  add_executable(SDL_part1 main.cpp Project_SDL1.cpp application.h Ground.h Character.cpp Character.h Position.cpp Position.h Ground.cpp Sheep.cpp Sheep.h Wolf.cpp Wolf.h Sheperd.cpp Sheperd.h Sheperd_dog.cpp Sheperd_dog.h WolfObserver.h SheepObserver.h GroundUtils.h application.cpp)
  target_link_libraries(SDL_part1 PUBLIC SDL2main SDL2 -static -static-libstdc++ -static-libgcc -lSDL2 -lSDL2_image)
ELSE()
  message(STATUS "Building for Linux or Mac")

  find_package(SDL2 REQUIRED)
  find_package(SDL2_IMAGE REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})
  include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

  add_executable(SDL_part1 main.cpp Project_SDL1.cpp application.h Ground.h Character.cpp Character.h Position.cpp Position.h Ground.cpp Sheep.cpp Sheep.h Wolf.cpp Wolf.h Sheperd.cpp Sheperd.h Sheperd_dog.cpp Sheperd_dog.h WolfObserver.h SheepObserver.h GroundUtils.h application.cpp)
  target_link_libraries(SDL_part1 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
ENDIF()