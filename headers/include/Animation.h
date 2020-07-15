#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Animation
{
private:
  /*Variables Miembro*/
  int nFrames;
  int currentFrame;
  float totalTime;
  float switchTime;
  /*Funciones Miembro*/

public:
  /*Variables Miembro*/
  IntRect uvRect;
  /*Funciones Miembro*/
  Animation();
  Animation(Texture *, int, float);
  ~Animation();
  void setAnim(Texture *, int, float);
  void setnFrames(int);
  void updateAnim(float, bool);
};
#endif