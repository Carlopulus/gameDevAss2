#include "Game.hpp"
#include <iostream>

int main() {
  std::cout << "Hola" << "\n";
  Game g("config.txt");

  g.run();
}
