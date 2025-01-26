#pragma once
//#include "ObjectCreators.h"
#include <vector>
#include <SFML/Graphics.hpp>

class RenderableInstance;

class Scene 
{
public:
	virtual ~Scene() = default;

	virtual void Render(sf::RenderWindow& window) = 0; // Wyœwietlanie sceny
	virtual void Update() = 0;                         // Aktualizacja logiki sceny
	virtual void HandleMouseClick(int x, int y) = 0;   // Obs³uga klikniêcia myszy
	
};


/*
/// <summary>
/// Zbiór ró¿nego rodzaju obiektów.
/// </summary>
class Scene
{
public:

	virtual ~Scene() = 0;

	/// <summary>
	/// Rysuje scenê na oknie.
	/// </summary>
	virtual void Draw() = 0;

private:


};
*/