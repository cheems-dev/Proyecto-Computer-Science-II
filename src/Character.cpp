#include "../headers/include/Character.h"

Character::Character(const Vector2f &pos){
  // Cargando texturas
  textCharIdle.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter_idle.png");
  textCharRun.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter_run.png");
  textCharAtk.loadFromFile("./assets/characters/1 Woodcutter/Woodcutter_attack1.png");
  spChar.setTexture(textCharIdle);
  spChar.setPosition(pos);
  // Animacion
  charAnim.setAnim(&textCharIdle,4,0.1f);
}

void Character::update(){
  // Movimiento del personaje
  deltaTime=clock.restart().asSeconds();

  if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
  {
    spChar.setTexture(textCharRun);
    charAnim.setnFrames(6);
    spChar.move(-charVel, 0);
    faceR=false;
  }
  else if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
  {
    spChar.setTexture(textCharRun);
    charAnim.setnFrames(6);
    spChar.move(charVel, 0);
    faceR = true;
  }
  else if(Keyboard::isKeyPressed(Keyboard::J))
  {
    spChar.setTexture(textCharAtk);
    charAnim.setnFrames(6);
  }
  else
  {
    spChar.setTexture(textCharIdle);
    charAnim.setnFrames(4);
  }

  charAnim.updateAnim(deltaTime, faceR);
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

Sprite &Character::getSprite(){
  return spChar;
}

// Pendiente enemy
bool Character::collidesWithEnemy(Enemy * e){
  
  FloatRect charRect = getSprite().getGlobalBounds();
  FloatRect ballRect = e->getSprite().getGlobalBounds();
  return charRect.intersects(ballRect);
}

