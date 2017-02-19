#include "MainGame.h"

MainGame::MainGame() {
  this->m_ScreenWidth = 1024;
  this->m_ScreenHeight = 768;
}

MainGame::~MainGame() {
  
}

void MainGame::run() {
  this->initSystems();
}

void MainGame::initSystems() {
  // Init SDL.
  SDL_Init(SDL_INIT_EVERYTHING);

  this->m_Window = SDLWrapper::createWindow("Game",
					    SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    this->m_ScreenWidth,
					    this->m_ScreenHeight,
					    SDL_WINDOW_OPENGL);
}

