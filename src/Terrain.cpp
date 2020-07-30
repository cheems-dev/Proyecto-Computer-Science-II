#include "../headers/include/Terrain.h"

Terrain::Terrain(Vector2f size, Vector2f position)
{
  terrText.loadFromFile("./assets/swamp-game-tileset/1 Tiles/Tile_02.png");
  terrSp.setTexture(terrText);
  terrSp.setPosition(position);
  terrSp.setOrigin(size/2.0f);
  body.setSize(size);
  body.setOrigin(size/2.0f);
  body.setPosition(position);
}

Terrain::~Terrain()
{
}

void Terrain::Draw(RenderWindow & window)
{
  window.draw(body);
  window.draw(terrSp);
}
