// #include "SFML/Window/Event.hpp"
// #include "SFML/Window/VideoMode.hpp"
// #include <string>
// #include "./src/Game.cpp"
#include "./src/Game_1.cpp"
#include "./src/PlayScene.cpp"

#include "./src/MenuScene.cpp"

// #include "./headers/include/PlayScene.h"
// #include "./headers/include/MenuScene.h"

using namespace sf;

int main(int argc, char const *argv[])
{
  BaseScene *scene = new MenuScene();
  Game &g = Game::create(VideoMode(576, 324), scene, "GTA 5");
  g.run();

  return 0;
}
