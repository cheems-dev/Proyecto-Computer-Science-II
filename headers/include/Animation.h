#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Animation
{
private:
  /*Variables Miembro*/
  Vector2u imageCount;
  Vector2u currentImage;
  float totalTime;
  float switchTime;
  /*Funciones Miembro*/

public:
  /*Variables Miembro*/
  IntRect uvRect;
  /*Funciones Miembro*/
  Animation();
  Animation(Texture *, Vector2u, float);
  ~Animation();
  void setAnim(Texture *, Vector2u, float);
  void updateAnim(int, float, bool);
};
#endif