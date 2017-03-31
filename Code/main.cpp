// main.cpp

// STL
#include <iostream>
#include <memory>

#include "MainGame.h"


int main() {
  std::unique_ptr<MainGame> mainGame = std::make_unique<MainGame>();
  mainGame->run();

  return 0;
}

