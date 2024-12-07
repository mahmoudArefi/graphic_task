#include "wardrobe.h"
#include "parallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include "myPolygon.h" 
#include "myTexture.h"
#include <iostream>
#include <fstream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>	
extern MYTEXTURE myTextureObj ; 

WARDROBE::WARDROBE(){
	rotateAngle = 0 ; 
	previousRotateAngle = -1 ; 
	isDoneEditDoorState = true; 
	 
}


void WARDROBE::draw(float h, float w, float l) {
    glPushMatrix(); // Save the current transformation state

    double doorH = h * 0.8; // Door height is 80% of wardrobe height
    float doorW = w * 0.5; // Each door is half the wardrobe width

    // Draw the main wardrobe body
    parallelRectangleObject.drawParallelRectangle(h*0.8, w, l, TextureType::wardrobe);

    // Draw the top section above the doors (if any)
    glPushMatrix();
    glTranslatef(0, h * 0.5 , 0); // Position for the top section
    parallelRectangleObject.drawParallelRectangle(h * 0.2, w, l, TextureType::comedina, true);
    glPopMatrix();

    // Draw the doors
    glPushMatrix();
    glTranslatef(0, 0, l * 0.5); // Move to the front face of the wardrobe

    // Left door
    glPushMatrix();
    glTranslatef(-doorW * 0.5, 0, 0); // Position the left door
	 
    drawWardrobeDoor(doorH,w,true) ;
    glPopMatrix();

    // Right door
    glPushMatrix();
    glTranslatef(doorW * 0.5, 0, 0); // Position the right door
    drawWardrobeDoor(doorH,w,false) ;
	 
    glPopMatrix();

    glPopMatrix(); // Restore the transformation state for doors
    glPopMatrix(); // Restore the overall transformation state
}


void WARDROBE::drawWardrobeDoor(float h, float w, bool isRightDoor) {   
    MYPOLYGON myPolygon; 

    glPushMatrix();

    // Translate to align rotation axis with the edge
    glTranslatef(isRightDoor ? -w * 0.25 : w * 0.25, 0, 0); 

    // Rotate the door around the edge
    glRotatef(isRightDoor ?  rotateAngle : -rotateAngle, 0, 1, 0);

    // Translate back to the original position
    glTranslatef(isRightDoor ? w * 0.25 : -w * 0.25, 0, 0); 


    float correctedHeight = h; // Explicitly set height to doorH
 

    myPolygon.drawPolygon(correctedHeight, w * 0.500, myTextureObj.wardrobeDoor);
   // myPolygon.drawPolygon(h , w * 0.500, myTextureObj.wardrobeDoor);

    glPopMatrix();
}


void WARDROBE::openOrCloseDoors(){
	
	isDoneEditDoorState = false ;

	if(rotateAngle==0){
		rotateAngle = 180 ; 
	}
	else {
		rotateAngle = 0 ;
	}

	return ;

	while(isDoneEditDoorState==false){
	float r = rotateAngle ; 
	if(previousRotateAngle<r) { 
			rotateAngle+= 0.5 ;
			std::cout<<rotateAngle << "increase" << std::endl ;
	}
	else 
	{
			rotateAngle-= 0.5 ;
			std::cout<<rotateAngle << "decrease" << std::endl ;
	}
	previousRotateAngle = r ; 


	if(rotateAngle<=0 ) {
		previousRotateAngle = -1 ; 
		rotateAngle = 0 ; 
		isDoneEditDoorState = true ; 
	}
	else if (rotateAngle >= 150) {
		previousRotateAngle = 155 ; 
		rotateAngle = 150 ; 
		isDoneEditDoorState = true ; 
	}
	}
	
}
