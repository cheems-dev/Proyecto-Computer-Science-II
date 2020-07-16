#ifndef ENEMY_H 
#define ENEMY_H 
#include "./Entity.h"
#include "../../src/Animation.cpp"
// Incluir enemy
// Standart C+11 -> Sobreescribir una funcion de una clase base
class Enemy : public Entity{
private:
  Sprite spEnemy;
  Texture textEnemy;
  // Velocidad del enemigo
  Vector2f vellEnemy;
  const float EnemyVel = 1;
  // Valores de acorde al tamaño de juego
  int valueX = 300, valueY = 200;
  // Animacion
  Animation enemyAnim;
  float deltaTime = 0.0f;
  Clock clock;
  bool faceR;

public:
  Enemy();
  // Manejo de escena
  void update()override;
  void draw(RenderWindow &)override;
  // Metodo que devuelva el sprite
  Sprite getSprite();
  // Cuando colisiona con el enemigo
};

#endif