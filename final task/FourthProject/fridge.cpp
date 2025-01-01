#include "fridge.h"
#include "parallelRectangle.h"
#include "myPolygon.h" 
#include "myTexture.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
extern MYTEXTURE myTextureObj ; 

 

// Constructor: Initializes the rotation angle to 0
FRIDGE::FRIDGE() {}
    

// Method to draw the rotating object
void FRIDGE::draw(float height , float weight , float length ) {
	h = height  ;
	w = weight ; 
	l = length ; 
	double doorH = h * 0.8; // Door height is 80% of wardrobe height
    float doorW = w * 0.5;

     glPushMatrix(); // Save the current transformation state
    //glRotatef(rotateAngle, 0, 1, 1); // Rotate around the Y-axis
     parallelRectangleObject.drawParallelRectangle(h, w, l,TextureType::fridge);
     glPopMatrix(); // Restore the transformation state
	 glPushMatrix();
    glTranslatef(0, 0, l * 0.5); 
	glPushMatrix();
	 
    drawFridgeDoor(h,w) ;
    glPopMatrix();
}

void FRIDGE::drawFridgeDoor(float h, float w) {   
    MYPOLYGON myPolygon; 

    glPushMatrix();

    float correctedHeight = h; // Explicitly set height to doorH
 

    myPolygon.drawPolygon(correctedHeight, w , myTextureObj.fridgeDoor);
   // myPolygon.drawPolygon(h , w * 0.500, myTextureObj.wardrobeDoor);

    glPopMatrix();
}


