#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "parallelRectangle.h"
#include "kitchen.h"

class Restaurant {
public:
    Restaurant(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float rH , rW , rD ; 
	ParallelRectangle prObj ;

	//kitchen functions
	


	//sallon functions
	void drawResturnSallon();
};

#endif // ROOMWALLS_H