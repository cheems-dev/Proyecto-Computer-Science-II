#include "../headers/include/Enemy.h"

Enemy::Enemy(){
  // Cargando texturas
  textEnemy.loadFromFile("./assets/desert-enemys/4 Vulture/Vulture.png");
  spEnemy.setTexture(textEnemy);
  srand(time(0));
  spEnemy.setPosition(rand()%valueX, rand()%valueY);
  vellEnemy.x = 2 + rand() % 3;
  vellEnemy.y = 2 + rand() % 3;
}

void Enemy::update(){
  spEnemy.move(vellEnemy);
  Vector2f charPosEnemy = spEnemy.getPosition();
  if(charPosEnemy.x < 0){
    charPosEnemy.x = 0;
    vellEnemy.x *= -1;
  }
  if(charPosEnemy.x > 500){
    charPosEnemy.x = 500;
    vellEnemy.x *= -1;
  }
  if(charPosEnemy.y < 0){
    charPosEnemy.y = 0;
    vellEnemy.y *= -1;
  }
  if(charPosEnemy.y > 300){
    charPosEnemy.y = 300;
    vellEnemy.y *= -1;
  }
  spEnemy.setPosition(charPosEnemy);
}

void Enemy::draw(RenderWindow &window){
  window.draw(spEnemy);
} 

Sprite &Enemy::getSprite(){
  return spEnemy;
}