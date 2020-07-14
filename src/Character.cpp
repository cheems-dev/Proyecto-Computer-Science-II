#include "../headers/include/Character.h"

Character::Character(const Vector2f &pos){
  // Cargando texturas
  textChar.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter_run.png");
  spChar.setTexture(textChar);
  spChar.setPosition(pos);
  // Animacion
  charAnim.setAnim(&textChar,6,0.2f);
}

void Character::update(){
  // Movimiento del personaje
  deltaTime=clock.restart().asSeconds();

  if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
  {
    spChar.move(-charVel, 0);
    charAnim.updateAnim(deltaTime,false);
  }
  if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
  {
    spChar.move(charVel, 0);
    charAnim.updateAnim(deltaTime, true);
  }
  
  spChar.setTextureRect(charAnim.uvRect);

  // Limitar el movimiento del personaje
  Vector2f charPos = spChar.getPosition();
  if(charPos.x < 0) charPos.x = 0;
  if(charPos.x > 500) charPos.x = 500;
  spChar.setPosition(charPos);

  
}

void Character::draw(RenderWindow &window){
  window.draw(spChar);
} 

Sprite Character::getSprite(){
  return spChar;
}

// Pendiente enemy
bool Character::collidesWithEnemy(Enemy *e){
  
  FloatRect charRect = getSprite().getGlobalBounds();
  FloatRect ballRect = e->getSprite().getGlobalBounds();
  return charRect.intersects(ballRect);
}

