#include "../headers/include/Animation.h"
Animation::Animation() {}
Animation::Animation(Texture *texture, int nFrames, float switchTime)
{
  //Establecer variables miembro
  this->nFrames = nFrames;
  this->switchTime = switchTime;
  totalTime = 0.0f;
  currentFrame = 0;

  //Establecer el tamaño de 1 frame
  uvRect.width = texture->getSize().x / nFrames;
  uvRect.height = texture->getSize().y;
}

void Animation::setAnim(Texture *texture, int nFrames, float switchTime)
{
  //Establecer variables miembro
  this->nFrames = nFrames;
  this->switchTime = switchTime;
  totalTime = 0.0f;
  currentFrame = 0;

  //Establecer el tamaño de 1 frame
  uvRect.width = texture->getSize().x / nFrames;
  uvRect.height = texture->getSize().y;
}

void Animation::setnFrames(int nFrames)
{
  this->nFrames = nFrames;
}

void Animation::updateAnim(float deltaTime, bool faceR)
{
  totalTime += deltaTime;
  if (totalTime >= switchTime)
  {
    totalTime -= switchTime;
    currentFrame++;

    if (currentFrame >= nFrames)
    {
      currentFrame = 0;
    }
  }
  uvRect.top = 0;

  // Analisis de la condición para girar el personaje
  if (faceR)
  {
    uvRect.left = currentFrame * uvRect.width;
    uvRect.width = abs(uvRect.width);
  }
  else
  {
    uvRect.left = (currentFrame + 1) * abs(uvRect.width);
    uvRect.width = -abs(uvRect.width);
  }
}

Animation::~Animation()
{
}