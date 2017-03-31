#pragma once

// STL
#include <memory>
#include <iostream>

// GL
#include <glad/glad.h>

// SDL
#include <SDL2/SDL.h>

#include "Utils/SDLWrapper.h"
#include "Utils/Logger.h"

#include "Sprite.h"

enum class GameState { PLAY, EXIT };

class MainGame {
public:
  MainGame();
  ~MainGame();

  void run();

private:
  SDLWrapper::WindowUniquePtr m_Window;
  int m_ScreenWidth;
  int m_ScreenHeight;
  GameState m_GameState;

  Sprite m_TestSprite;

  void initSystems();

  void processInput();

  void drawGame();

  void gameLoop();
};

