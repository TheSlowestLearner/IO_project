#pragma once
#include "ObjectCreators.h"

/// <summary>
/// Zbiór ró¿nego rodzaju obiektów.
/// </summary>
class Scene
{
public:

	virtual ~Scene() = 0;

private:

	std::vector<Decoration*>	decorationVector;
	std::vector<Button*>		buttonVector;
};