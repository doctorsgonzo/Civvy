//
//  CivWorld.hpp
//  MyCppGame
//
//  Created by Ben Williams on 10/2/17.
//
//

#ifndef CivWorld_hpp
#define CivWorld_hpp

#include <stdio.h>
#include "CivTile.hpp"

class CivWorld
{
public:
	CivWorld();
	~CivWorld();

	const static int maxWorldWidth = 2;
	const static int maxWorldHeight = 2;

	CivTile tiles[CivWorld::maxWorldWidth][CivWorld::maxWorldHeight];
};


#endif /* CivWorld_hpp */
