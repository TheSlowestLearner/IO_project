#pragma once
#include "ObjectCreators.h"

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