#pragma once

// STL
#include <memory>
#include <string>
#include <cstdint>

// SDL
#include <SDL2/SDL.h>

namespace SDLWrapper {
  struct sdl_deleter {
    void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
    void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
    void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
  };

  using WindowUniquePtr = std::unique_ptr<SDL_Window, sdl_deleter>;

  WindowUniquePtr createWindow(const std::string& title,
			       int x, int y,
			       int width, int height,
			       std::uint32_t flags);
};

