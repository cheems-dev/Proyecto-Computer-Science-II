#ifndef CHARACTER_H 
#define CHARACTER_H 

#include "./Entity.h"
#include "../../src/Enemy.cpp"
// Incluir enemy
// Standart C+11 -> Sobreescribir una funcion de una clase base
class Character : public Entity{
private:
  Sprite spChar;
  Texture textChar;
  const float charVel = 5;
  
public:
  Character(const Vector2f &);
  // Manejo de escena
  void update()override;
  void draw(RenderWindow &)override;
  // Metodo que devuelva el sprite
  Sprite &getSprite();
  // Cuando colisiona con el enemigo
  bool collidesWithEnemy(Enemy *);
};

#endif