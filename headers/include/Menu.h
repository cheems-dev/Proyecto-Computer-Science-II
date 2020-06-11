#ifndef MENU_H //que onda con esto para que sirve
#define MENU_H //x2

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
  
  Texture texLogo;
  Texture texBackground;
  Texture texPlay;
  Texture texRecords;
  Texture texExit;

  Sprite spLogo;
  Sprite spBackground;
  Sprite spPlay;
  Sprite spRecords;
  Sprite spExit;

  void Init();
  void Update();
  void Draw();
};
#endif