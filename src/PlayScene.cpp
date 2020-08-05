#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "../headers/include/PlayScene.h"
#include "../headers/include/MenuScene.h"
#include "../headers/include/Game_1.h"
using namespace std;

PlayScene::PlayScene()
{
    // Crear el personaje
    player = new Character(Vector2f(100, 200));
    add(player);

    minVel = 150;
    createNewBall(minVel);
    timeToNewBall.restart();

    // Music
    if (!bgm.openFromFile("./assets/music/GameBGM.wav"))
        cout << "error" << endl;
    else
    {
        bgm.setLoop(true);
        bgm.play();
    }
    // Music

    // Puntaje
    if (!fontScoreText.loadFromFile("/home/davaria/Documentos/repositories/Proyecto-Computer-Science/assets/font/Cave-Story.ttf"))
    {
        cerr << "ERROR: no se encontro la fuente "
            << "PlayScene.cpp"
            << endl;
    }
    // Puntaje
    // Texturas de nuestros videojuego
    textBackground.loadFromFile("./assets/swamp-game-tileset/2 Background/Background.png");
    spBackground.setTexture(textBackground);
    // Texturas de nuestros videojuego

    score = 0;
    scoreText.setFont(fontScoreText);
    scoreText.setFillColor(Color::White);
}

void PlayScene::update(float elapsed)
{
    //  actualiza el personaje
    BaseScene::update(elapsed);
    // creamos nuevo enemigo
    if (timeToNewBall.getElapsedTime().asSeconds() > 20)
    {
        minVel += 20;
        createNewBall(minVel);
        timeToNewBall.restart();
    }
    // Colisiones entre el personaje y las pelotas
    for (const auto &ball : balls)
    {
        if (player->collidesWithEnemy(ball))
        {
            //Dos opciones enter o esc

            if (score > Global::highScore)
                Global::highScore = score;
            cout << "Programar exit " << endl;
            // Game::getInstance().switchScene(new MenuScene());
        }
    }

    // actualiza el puntaje
    score += elapsed;
    stringstream tmp;
    tmp << "PUNTAJE: " << int(score);
    scoreText.setString(tmp.str());
}

void PlayScene::draw(RenderWindow &window)
{
    // Limpia la pantalla
    window.draw(spBackground);
    BaseScene::draw(window);
    window.draw(scoreText);
}

void PlayScene::createNewBall(float minVel)
{
    Enemy *b = new Enemy();
    balls.push_back(b);
    add(b);
}