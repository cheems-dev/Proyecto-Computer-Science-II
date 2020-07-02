#include "../headers/include/Animation.h"
Animation::Animation(){}
Animation::Animation(Texture *texture, Vector2u imageCount, float switchTime)
{ 
  this->imageCount = imageCount;
  this->switchTime = switchTime;
  totalTime = 0.0f;
  currentImage.x = 0;

  uvRect.width = texture->getSize().x / float(imageCount.x);
  uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::setAnim(Texture *texture, Vector2u imageCount, float switchTime)
{
  this->imageCount = imageCount;
  this->switchTime = switchTime;
  totalTime = 0.0f;
  currentImage.x = 0;

  uvRect.width = texture->getSize().x / float(imageCount.x);
  uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::updateAnim(int row, float deltaTime ,bool faceR)
{
  currentImage.y = row;
  totalTime += deltaTime;
  if (totalTime >= switchTime)
  {
    totalTime -= switchTime;
    currentImage.x++;

    if (currentImage.x >= imageCount.x)
    {
      currentImage.x = 0;
    }
  }
  uvRect.top = currentImage.y * uvRect.height;
  if(faceR)
  {
    uvRect.left = currentImage.x * uvRect.width;
  }
  else
  {
    uvRect.left = (currentImage.x +1) * abs(uvRect.width);
    uvRect.width = -abs(uvRect.width);
  } 
}

Animation::~Animation()
{
}