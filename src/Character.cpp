#include "../headers/include/Character.h"

Character::Character(const Vector2f &pos){
  // Cargando texturas
  textChar.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter.png");
  spChar.setTexture(textChar);
  spChar.setPosition(pos);
}

void Character::update(){
  // Movimiento del personaje
  if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Right))
    spChar.move(-charVel, 0);
  if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Left))
    spChar.move(charVel, 0);
  
  // Limitar el movimiento del personaje
  Vector2f charPos = spChar.getPosition();
  if(charPos.x < 0) charPos.x = 0;
  if(charPos.x > 500) charPos.x = 500;
  spChar.setPosition(charPos);
}

void Character::draw(RenderWindow &window){
  window.draw(spChar);
} 

Sprite &Character::getSprite(){
  return spChar;
}

// Pendiente enemy
bool Character::collidesWithEnemy(Enemy * e){
  
  FloatRect charRect = getSprite().getGlobalBounds();
  FloatRect ballRect = e->getSprite().getGlobalBounds();
  return charRect.intersects(ballRect);
}

