#ifndef KITCHEN_H
#define KITCHEN_H

#include "parallelRectangle.h"

class Kitchen {
public:
	Kitchen();
    Kitchen(float height, float width, float depth);                              
	void draw();
	void openAndCloseDoor(bool isOpen);

private : 
	ParallelRectangle prObj ;
	float kH , kW , kD ; 
	
	float manholeH , manholeW , manholeD ;
	
	float interfaceD ; 

	//door
	float doorAngle ; 

	void drawManhole(bool isType1);
	void drawInterface();
	
};

#endif // ROOMWALLS_H