#pragma once

// STL
#include <memory>

// GL
#include <glad/glad.h>

// SDL
#include <SDL2/SDL.h>

#include "Utils/SDLWrapper.h"

class MainGame {
public:
  MainGame();
  ~MainGame();

  void run();
  
  void initSystems();

private:
  SDLWrapper::WindowUniquePtr m_Window;
  int m_ScreenWidth;
  int m_ScreenHeight;
};

