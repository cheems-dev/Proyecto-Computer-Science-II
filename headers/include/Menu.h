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

  Vector2f vellEnemy;
  Texture texLogo;
  Texture texBackground;
  Texture texPlay;
  Texture texRecords;
  Texture texExit;
  Texture texChar;
  Texture textEnemy;
  Sprite spLogo;
  Sprite spBackground;
  Sprite spPlay;
  Sprite spRecords;
  Sprite spExit;
  Sprite spChar;
  Sprite spEnemy;

  void Init();
  void Update();
  void Draw();
};
#endif