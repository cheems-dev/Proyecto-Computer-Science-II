#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP
#include "./BaseScene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;
class MenuScene : public BaseScene
{
    Text titleText;
    Text scoreText;
    Text pressStartText;
    Font titleFont;

public:
    MenuScene();
    void update(float elapsed);
    void draw(RenderWindow &w);
};

#endif
