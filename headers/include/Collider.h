#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Collider
{
public:
  Collider(RectangleShape &body);
  ~Collider();

  void Move(float dx, float dy) { body.move(dx, dy); }

  bool CheckCollision(Collider &, float );

  Vector2f GetPosition() { return body.getPosition(); }
  Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
  RectangleShape &body;
};

#endif