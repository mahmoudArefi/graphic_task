#ifndef WARDROBE_H
#define WARDROBE_H
#include "parallelRectangle.h"

class WARDROBE {
private:
    float rotateAngle;
	float previousRotateAngle ; 
	bool isDoneEditDoorState ; 
	bool isOpenMode ; 
    ParallelRectangle parallelRectangleObject ; // Create the rectangle object
    void drawWardrobeDoor(float h , float w,bool isRightDoor );


public:
    WARDROBE(); // Constructor with default values
    void draw(float h , float w , float l);              // Method to draw the object with rotation
	void openOrCloseDoors();
};

#endif // COMEDINA_H
