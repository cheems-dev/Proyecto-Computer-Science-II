#include "../headers/include/EndScene.h"
#include "../headers/include/MenuScene.h"
#include "../headers/include/Game.h"
#include "../headers/include/PlayScene.h"
#include "../headers/include/Global.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

EndScene::EndScene()
{
    if (!titleFont.loadFromFile("./assets/font/Cave-Story.ttf"))
    {
        cerr << "ERROR: no se encontro la fuente "
            << "EndScene.cpp" << endl;
    }
    titleText.setFont(titleFont);
    titleText.setFillColor(Color::White);
    titleText.setString("GAME OVER");
    titleText.setCharacterSize(120);
    // centra el texto
    titleText.setPosition(Vector2f((580 - titleText.getLocalBounds().width) / 2.0, 0));

    scoreText.setFont(titleFont);
    scoreText.setFillColor(Color::White);
    stringstream ss;
    ss << "Puntaje Maximo: " << Global::highScore;
    scoreText.setString(ss.str());
    scoreText.setCharacterSize(40);
    scoreText.setPosition(Vector2f((580 - scoreText.getLocalBounds().width) / 2.0, 150));

    pressStartText.setFont(titleFont);
    pressStartText.setFillColor(Color::White);
    pressStartText.setString("Presione ENTER para volver");
    pressStartText.setCharacterSize(40);
    pressStartText.setPosition(Vector2f((580 - pressStartText.getLocalBounds().width) / 2.0, 250));
}

void EndScene::update(float elapsed)
{
    if (Keyboard::isKeyPressed(Keyboard::Return))
    {
        cout << "Presiono enter" << endl;
        Game::getInstance().switchScene(new PlayScene());
    }
}

void EndScene::draw(RenderWindow &w)
{
    BaseScene::draw(w);
    w.draw(titleText);
    w.draw(scoreText);
    w.draw(pressStartText);
}