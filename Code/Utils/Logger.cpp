#include "Logger.h"

namespace Logger {
  void fatalError(const std::string& error) {
    std::cout << error << std::endl;
    std::cout << "Enter any key to quit... ";
    char tmp;
    std::cin >> tmp;
    SDL_Quit();
    exit(1);
  }

  void sdlError(const std::string& error) {
    std::cout << error << ": " << SDL_GetError() << std::endl;
    std::cout << "Enter any key to quit... ";
    char tmp;
    std::cin >> tmp;
    exit(1);
  }
}

