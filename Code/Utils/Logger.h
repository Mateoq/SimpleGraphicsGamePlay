#pragma once

// STL
#include <string>
#include <iostream>

// SDL
#include <SDL2/SDL.h>

namespace Logger {
  void fatalError(const std::string& error);

  void sdlError(const std::string& error);
}

