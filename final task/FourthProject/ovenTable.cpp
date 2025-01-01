#include "parallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include "myTexture.h"
#include "ovenTable.h"
#include "myPolygon.h" 
extern MYTEXTURE myTextureObj ; 

OVEN_TABLE::OVEN_TABLE(){
	roateAngle = 180 ; 
}

void OVEN_TABLE::draw(float h , float w , float l){
	ParallelRectangle parallelRectangle ; 

	parallelRectangle.drawParallelRectangle(h*0.15,w,l,TextureType::comedina,true) ;

	float legH = h *0.85 ; 
	float legWL = w *0.04;
	glPushMatrix();
    glTranslatef(-(w/2-legWL/2) , -(legH/2 +(h*0.15/2)), l/2 -legWL/2);
		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
    glTranslatef(w-legWL,0,0);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
      glTranslatef(0,0 , legWL-l);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
     glTranslatef(legWL-w,0 , 0);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -h * 0.5, 0);
	glTranslatef(w * 0.25, 0, 0);
	drawOven(legH, w*0.5 , l);
	glPopMatrix();
     
}

void OVEN_TABLE::drawOven(float h , float w , float l){
	double doorH = h * 0.8; // Door height is 80% of wardrobe height
    float doorW = w * 0.5;
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
    glTranslatef(0, -h*0.5, 0); 

    // Rotate the door around the edge
    glRotatef(roateAngle, 1, 0, 0);

    // Translate back to the original position
    glTranslatef( 0, -h*0.5, 0); 


 
 

     myPolygon.drawPolygon(correctedHeight, w , myTextureObj.ovenDoor);
   // myPolygon.drawPolygon(h , w * 0.500, myTextureObj.wardrobeDoor);

    glPopMatrix();
   // myPolygon.drawPolygon(h , w * 0.500, myTextureObj.wardrobeDoor);

    glPopMatrix();
}

void OVEN_TABLE::openCloseDoor(int state){
	if(state == 0 ) {roateAngle=180;}
	else if(state == 1 ) {roateAngle=60+180;}
}
