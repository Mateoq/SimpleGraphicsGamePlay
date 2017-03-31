#include "MainGame.h"

MainGame::MainGame() {
  this->m_ScreenWidth = 1024;
  this->m_ScreenHeight = 768;
  this->m_GameState = GameState::PLAY;
}

MainGame::~MainGame() {
  
}

void MainGame::run() {
  this->initSystems();

  this->m_TestSprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

  this->gameLoop();
}

void MainGame::initSystems() {
  // Init SDL.
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    Logger::sdlError("Could not initialize SDL");
  }

  // Set SDL attributes.
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  // Create Window.
  this->m_Window = SDLWrapper::createWindow("Game",
					    SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    this->m_ScreenWidth,
					    this->m_ScreenHeight,
					    SDL_WINDOW_OPENGL);

  if (this->m_Window == nullptr || this->m_Window == NULL) {
    Logger::sdlError("SDL Window could not be created");
  }

  // Create OpenGL Context.
  SDL_GLContext glContext = SDL_GL_CreateContext(this->m_Window.get());

  if (glContext == nullptr) {
    Logger::sdlError("SDL_GL context could not be created");
  }

  // Load Glad.
  if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
    Logger::fatalError("Failed to initialize OpenGL context");
  }

  // Set background color.
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void MainGame::processInput() {
  SDL_Event inputEvent;

  while (SDL_PollEvent(&inputEvent)) {
    switch (inputEvent.type) {
    case SDL_QUIT:
      this->m_GameState = GameState::EXIT;
      break;
    case SDL_MOUSEMOTION:
      std::cout << inputEvent.motion.x << ", " << inputEvent.motion.y << std::endl;
      break;
    default:
      std::cout << "Unkown input" << std::endl;
      break;
    }
  }
}

void MainGame::drawGame() {
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->m_TestSprite.draw();

  SDL_GL_SwapWindow(this->m_Window.get());
}

void MainGame::gameLoop() {
  while (this->m_GameState != GameState::EXIT) {
    this->processInput();
    this->drawGame();
  }
}

