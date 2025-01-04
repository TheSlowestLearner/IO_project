#pragma once
#include "ObjectCreators.h"

/// <summary>
/// Zbi�r r�nego rodzaju obiekt�w.
/// </summary>
class Scene
{
public:

	virtual ~Scene() = 0;

private:

	std::vector<Decoration*>	decorationVector;
	std::vector<Button*>		buttonVector;
};