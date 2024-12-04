#ifndef WARDROBE_H
#define WARDROBE_H
#include "parallelRectangle.h"

class WARDROBE {
private:
    float rotateAngle; 
    ParallelRectangle parallelRectangleObject ; // Create the rectangle object
    void drawWardrobeDoor(int h , int w);


public:
    WARDROBE(); // Constructor with default values
    void draw(int h , int w , int l);              // Method to draw the object with rotation
};

#endif // COMEDINA_H
