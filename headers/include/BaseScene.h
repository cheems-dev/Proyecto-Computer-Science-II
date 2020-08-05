#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "./Entity.h"
#include <vector>
using namespace std;
using namespace sf;
/***
 * Representa una escena del juego.
 * Para crear una nueva clase de escena, heredar de esta clase
 * y redefinir el comportamiento de los metodos
 */
class BaseScene
{
  vector<Entity *> entities;
  vector<Entity *> to_delete;

public:
  /// constructor
  // BaseScene();

  /// funcion que sera invocada para actualizar la escena
  virtual void update(float);

  /// funcion que sera invocada para dibujar la escena
  virtual void draw(RenderWindow &);

  /// funcion que sera invocada para notificar a la escena de un evento
  virtual void process_event(const Event &);

  /// agrega un nuevo actor a la escena
  void add(Entity *);

  /// eliminar un actor de la escena
  void remove(Entity *e);
};

#endif
