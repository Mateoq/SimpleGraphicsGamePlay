#include "SDLWrapper.h"

namespace SDLWrapper {
  WindowUniquePtr createWindow(const std::string& title,
			       int x, int y,
			       int width, int height,
			       std::uint32_t flags) {
    return WindowUniquePtr(SDL_CreateWindow(title.c_str(), x, y, width, height, flags),
			   sdl_deleter());
  }
}

