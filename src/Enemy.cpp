#include "../headers/include/Enemy.h"

Enemy::Enemy()
{
  // Cargando texturas
  textEnemy.loadFromFile("./assets/desert-enemys/4 Vulture/Vulture_walk.png");
  spEnemy.setTexture(textEnemy);

  srand(time(0));
  spEnemy.setPosition(rand() % valueX, rand() % valueY);
  vellEnemy.x = 2 + rand() % 2;
  vellEnemy.y = 2 + rand() % 2;

  // Animacion
  enemyAnim.setAnim(&textEnemy, 4, 0.1f);
}

void Enemy::update(float elapsed)
{
  deltaTime = clock.restart().asSeconds();
  // mover al enemigo
  spEnemy.move(vellEnemy);
  // limitar el movimiento del enemigo
  Vector2f charPosEnemy = spEnemy.getPosition();
  if (charPosEnemy.x < 0)
  {
    charPosEnemy.x = 0;
    vellEnemy.x *= -1;
    faceR = false;
  }
  if (charPosEnemy.x > 500)
  {
    charPosEnemy.x = 500;
    vellEnemy.x *= -1;
    faceR = true;
  }
  if (charPosEnemy.y < 0)
  {
    charPosEnemy.y = 0;
    vellEnemy.y *= -1;
  }
  if (charPosEnemy.y > 300)
  {
    charPosEnemy.y = 300;
    vellEnemy.y *= -1;
  }

  enemyAnim.updateAnim(deltaTime, faceR);
  spEnemy.setTextureRect(enemyAnim.uvRect);
  spEnemy.setPosition(charPosEnemy);
}

void Enemy::draw(RenderWindow &window)
{
  window.draw(spEnemy);
}

Sprite Enemy::getSprite()
{
  return spEnemy;
}