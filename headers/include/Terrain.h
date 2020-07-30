#ifndef TERRAIN_H
#define TERRAIN_H

#include "../../src/Collider.cpp"
using namespace sf;

class Terrain
{
private:
  RectangleShape body;
  Texture terrText;
  Sprite terrSp;

public:
  Terrain();
  Terrain( Vector2f, Vector2f);
  ~Terrain();

  void Draw(RenderWindow &);
  Collider getCollider() { return Collider(body);}
};

#endif