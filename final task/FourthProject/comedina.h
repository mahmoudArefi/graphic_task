#ifndef COMEDINA_H
#define COMEDINA_H
#include "parallelRectangle.h"

class COMEDINA {
private:
    int staircaseToOpenNum ; 
    float h, w, l; 
    ParallelRectangle parallelRectangleObject ; // Create the rectangle object
    void drawStaircase(int rank);

public:
    COMEDINA(); // Constructor with default values
    void draw(float h , float w , float l);              // Method to draw the object with rotation
	void openOrCloseStaircase(int sRank ) ;
};

#endif // COMEDINA_H
