#include "parallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include "myTexture.h"
#include "microwave.h"
#include "myPolygon.h" 
extern MYTEXTURE myTextureObj ; 

MICROWAVE::MICROWAVE(){
	rotateAngle = 180 ; 
}

void MICROWAVE::draw(float h , float w , float l){
	ParallelRectangle parallelRectangle ; 

     glPushMatrix(); // Save the current transformation state
    //glRotatef(rotateAngle, 0, 1, 1); // Rotate around the Y-axis
     parallelRectangle.drawParallelRectangle(h, w, l,TextureType::fridge);
     glPopMatrix(); // Restore the transformation state
	 glPushMatrix();
    glTranslatef(0, 0, l * 0.5); 
    glPopMatrix();

	glTranslatef(0, 0, l * 0.5); 
	MYPOLYGON myPolygon; 

    glPushMatrix();

    float correctedHeight = h; // Explicitly set height to doorH
 
	

	 glPushMatrix();

    // Translate to align rotation axis with the edge
    glTranslatef( w * 0.5, 0, 0); 

    // Rotate the door around the edge
    glRotatef(rotateAngle, 0, 1, 0);

    // Translate back to the original position
    glTranslatef(  w * 0.5, 0, 0); 

 

    myPolygon.drawPolygon(correctedHeight, w , myTextureObj.microDoor);
   // myPolygon.drawPolygon(h , w * 0.500, myTextureObj.wardrobeDoor);

    glPopMatrix();


}


void MICROWAVE::openCloseDoor(int s ) {
		std::cout<<"the state = " << s << "and rotated anlge is " << rotateAngle << "the new one is "  ; 
	if(s==0){ 
		rotateAngle =  180; 
	
	}
	else if (s==1){
		rotateAngle = -20 ; 
	}

	std::cout<<rotateAngle<< std::endl ;

}





 