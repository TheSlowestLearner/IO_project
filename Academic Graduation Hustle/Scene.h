#pragma once
#include "ObjectCreators.h"

/// <summary>
/// Zbi�r r�nego rodzaju obiekt�w.
/// </summary>
class Scene
{
public:

	virtual ~Scene() = 0;

	/// <summary>
	/// Rysuje scen� na oknie.
	/// </summary>
	virtual void Draw() = 0;

private:


};