#ifndef STAND1_H
#define STAND1_H

#include "parallelRectangle.h"


class Stand1 {
public:
    Stand1(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float sH , sW , sD ; 
	ParallelRectangle prObj ;
};

#endif // ROOMWALLS_H