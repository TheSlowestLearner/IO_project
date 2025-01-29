#include "Animator.h"

Animator::Animator(sf::Sprite& sprite, sf::Vector2i frameSize, int frameCount, int row, float animationSpeed)
    : sprite(sprite), frameSize(frameSize), frameCount(frameCount), currentFrame(0), currentRow(row), animationSpeed(animationSpeed), timeElapsed(0.0f)
{
    UpdateSpriteTextureRect();
}

int Animator::Update(float deltaTime)
{
    timeElapsed += deltaTime;
    if (timeElapsed >= animationSpeed)
    {
        timeElapsed = 0.0f;
        currentFrame = (currentFrame + 1) % frameCount; 
        UpdateSpriteTextureRect();
    }
    return currentFrame;
}

void Animator::SetAnimation(int row, int frameCount)
{
    currentRow = row;
    this->frameCount = frameCount;
    currentFrame = 0; 
    timeElapsed = 0.0f;
    UpdateSpriteTextureRect();
}

void Animator::Reset()
{
    currentFrame = 0;
    timeElapsed = 0.0f;
    UpdateSpriteTextureRect();
}

void Animator::UpdateSpriteTextureRect()
{
    int x = currentFrame * frameSize.x; 
    int y = currentRow * frameSize.y;  
    sprite.setTextureRect(sf::IntRect(x, y, frameSize.x, frameSize.y));
}