#ifndef ENDSCENE_HPP
#define ENDSCENE_HPP
#include "./BaseScene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class EndScene : public BaseScene
{
  sf::Text titleText;
  sf::Text scoreText;
  sf::Text pressStartText;
  sf::Font titleFont;

public:
  EndScene();
  void update(float elapsed);
  void draw(sf::RenderWindow &w);
};

#endif
