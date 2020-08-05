#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../src/BaseScene.cpp"
using namespace std;
using namespace sf;

/***
 * Clase para manejar un bucle de juego con distintas escenas
 */
class Game
{

  RenderWindow window;
  BaseScene *currentScene, *nextScene;
  Clock clock;

  void processEvents();
  void update();
  void draw();
  static Game *instance;
  Game();

public:
  /// comenzar el bucle de juego
  void run();

  /// cambiar la escena actual por otra
  void switchScene(BaseScene *scene);

  /// obtener la instancia de juego (singleton)
  static Game &getInstance();

  /// crear un juego especificando el modo de video y la escena inicial
  static Game &create(const VideoMode &videoMode, BaseScene *scene, const string &name = "");
};

#endif
