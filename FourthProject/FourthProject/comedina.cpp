#include "comedina.h"
#include "parallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>


 

// Constructor: Initializes the rotation angle to 0
COMEDINA::COMEDINA(float initH, float initW, float initL) 
    : rotateAngle(0), h(initH), w(initW), l(initL) {}

// Method to draw the rotating object
void COMEDINA::draw() {
    glPushMatrix(); // Save the current transformation state
    //glRotatef(rotateAngle, 0, 1, 1); // Rotate around the Y-axis
    parallelRectangleObject.drawParallelRectangle(h, w, l,TextureType::comedina);
	drawStaircase(1);
	drawStaircase(2);
	drawStaircase(3);
    glPopMatrix(); // Restore the transformation state
    

}


void COMEDINA::drawStaircase(int rank){
	if(rank<0 || rank > 3 ){return;}
	glPushMatrix();

	glTranslated(0,(4-(2*rank))*(h/6) ,0);
	glRotatef(-90, 1, 0, 0); // Rotate around the Y-axis
	parallelRectangleObject.drawParallelRectangle(l,w,h/3,TextureType::Staircase);

	glPopMatrix();
}


