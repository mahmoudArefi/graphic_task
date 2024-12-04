#ifndef COMEDINA_H
#define COMEDINA_H
#include "parallelRectangle.h"

class COMEDINA {
private:
    float rotateAngle; 
    float h, w, l; 
    ParallelRectangle parallelRectangleObject ; // Create the rectangle object
    void drawStaircase(int rank);

public:
    COMEDINA(float initH = 5.0f, float initW = 4.0f, float initL = 4.0f); // Constructor with default values
    void draw();              // Method to draw the object with rotation
};

#endif // COMEDINA_H
