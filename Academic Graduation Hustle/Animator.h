#pragma once
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator(sf::Sprite& sprite, sf::Vector2i frameSize, int frameCount, int row, float animationSpeed);

    int Update(float deltaTime); 
    void SetAnimation(int row, int frameCount); 
    void Reset(); 

private:
    sf::Sprite& sprite;
    sf::Vector2i frameSize; 
    int frameCount;        
    int currentFrame;      
    int currentRow;         
    float animationSpeed;   
    float timeElapsed;      

    void UpdateSpriteTextureRect(); 
};