#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
using namespace sf;
using namespace std;

class Menu
{
public:
  Menu();
  ~Menu();
  // void Init(int, int, string);
  void Run();

private:
  // int fps
  RenderWindow *window;
  Texture textChar;
  Texture texBackground;
  Sprite spChar;
  Sprite spBackground;

  void Init();
  void Update();
  void Draw();
};
#endif