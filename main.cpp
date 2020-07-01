#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <string>
#include "./src/Game.cpp"

using namespace sf;
using namespace std;

int main()
{
  Game menu;
  menu.run();
  return 0;
}