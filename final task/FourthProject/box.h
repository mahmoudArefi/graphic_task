#ifndef BOX_H
#define BOX_H

#include "parallelRectangle.h"


class Box {
public:
    Box(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float h , w , d ; 
	ParallelRectangle prObj ;
};

#endif // ROOMWALLS_H