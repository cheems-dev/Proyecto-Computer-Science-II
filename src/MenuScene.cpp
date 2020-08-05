#include "../headers/include/MenuScene.h"
// #include "Game.h"
// #include "PlayScene.h"
#include "../headers/include/Game_1.h"
#include "../headers/include/PlayScene.h"
#include "../headers/include/Global.h"
#include <iostream>
#include <sstream>

// #include "Global.hpp"
using namespace std;
using namespace sf;

MenuScene::MenuScene()
{
  if (!titleFont.loadFromFile("/home/davaria/Documentos/repositories/Proyecto-Computer-Science/assets/font//Cave-Story.ttf"))
  {
    cerr << "ERROR: no se encontro la fuente "
         << "MenuScene.cpp" << endl;
  }
  titleText.setFont(titleFont);
  titleText.setFillColor(Color::White);
  titleText.setString("Ejemplo SFML");
  titleText.setCharacterSize(120);
  // centra el texto
  titleText.setPosition(Vector2f((640 - titleText.getLocalBounds().width) / 2.0, 0));

  scoreText.setFont(titleFont);
  scoreText.setFillColor(Color::White);
  stringstream ss;
  ss << "Puntaje total: " << Global::highScore;
  scoreText.setString(ss.str());
  scoreText.setCharacterSize(40);
  scoreText.setPosition(Vector2f((640 - scoreText.getLocalBounds().width) / 2.0, 150));

  pressStartText.setFont(titleFont);
  pressStartText.setFillColor(Color::White);
  pressStartText.setString("Presione ENTER para comenzar");
  pressStartText.setCharacterSize(40);
  pressStartText.setPosition(Vector2f((640 - pressStartText.getLocalBounds().width) / 2.0, 250));
}

void MenuScene::update(float elapsed)
{
  if (Keyboard::isKeyPressed(Keyboard::Return))
  {
    cout << "Presiono enter" << endl;
    Game::getInstance().switchScene(new PlayScene());
  }
}

void MenuScene::draw(RenderWindow &w)
{
  BaseScene::draw(w);
  w.draw(titleText);
  w.draw(scoreText);
  w.draw(pressStartText);
}