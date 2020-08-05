#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../src/Character.cpp"
#include "../../src/Global.cpp"
#include "./BaseScene.h"
#include "./Enemy.h"

using namespace std;
using namespace sf;

class PlayScene : public BaseScene
{
    Character *player;      //nuestro personaje
    vector<Enemy *> balls;  //arreglo con pelotas
    float minVel;           //Velocidad en la que un enemigo se creara
    Clock timeToNewBall;    // tiempo para crear x enemigos
    float score;            // puntaje
    Text scoreText;         // texto para mostrar el puntaje
    Font fontScoreText;     // fuente del texto
    Texture textBackground; // textura del fondo
    Sprite spBackground;    // sprite del fondo
    // Enemy *enemy;
    Music bgm;

    void createNewBall(float); // crear una nueva pelota

public:
    PlayScene();
    void update(float);
    void draw(RenderWindow &);
};

#endif