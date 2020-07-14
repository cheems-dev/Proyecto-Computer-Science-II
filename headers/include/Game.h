#ifndef GAME_H 
#define GAME_H 

#include "../../src/Character.cpp"
#include "./Entity.h"
#include <vector>

using namespace std;

class Game
{
  RenderWindow window;
  Texture texBackground;
  Sprite spBackground;

  // Personaje y enemigos
  Character *character;
  Enemy *enemy;
  // Vector de punteros , invocar poliformicamente update, draw
  vector<Entity * > entities;
  // tamaño definido 
  int height = 576;
  int width = 324;

  void init();
  void update();
  void draw();

public:
  Game();
  void run();
  void add(Entity *);
  // ~Game();
};

#endif