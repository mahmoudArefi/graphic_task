#ifndef FRIDGE_H
#define FRIDGE_H
#include "parallelRectangle.h"

class FRIDGE {
private:
    float h, w, l; 
    ParallelRectangle parallelRectangleObject ; 

public:
    FRIDGE();
    void draw(float h , float w , float l);
	 void drawFridgeDoor(float h , float w );
};

#endif
