// main.cpp

// STL
#include <iostream>
#include <memory>

#include "MainGame.h"


int main() {
  std::unique_ptr<MainGame> mainGame = std::make_unique<MainGame>();
  mainGame->run();

  std::cout << "Enter any key to quit... ";
  char a;
  std::cin >> a;

  return 0;
}

