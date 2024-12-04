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

extern MYTEXTURE myTextureObj ; 

WARDROBE::WARDROBE(){

}

void WARDROBE::draw(int h , int w ,int l ){
	glPushMatrix(); // Save the current transformation state
    //glRotatef(rotateAngle, 0, 1, 1); // Rotate around the Y-axis
    parallelRectangleObject.drawParallelRectangle(h, w, l,TextureType::wardrobe);

	glPushMatrix();
	glTranslatef(0 ,h*0.6,0 ) ;
		    parallelRectangleObject.drawParallelRectangle(h/4, w, l,TextureType::wardrobe,true);
	glPopMatrix();

	glTranslatef(0 ,-h/2, l/1.9 ) ;
	drawWardrobeDoor(h,w) ;

	glTranslatef(-w/2 ,0, 0) ;
	drawWardrobeDoor(h,w) ;


	//drawWardrobeDoor(h,w) ;
    glPopMatrix(); // Restore the transformation state
}


void WARDROBE::drawWardrobeDoor(int h , int w ){   
   MYPOLYGON myPolygon ; 
   myPolygon.drawPolygon(0,0,h,w/2,myTextureObj.wardrobeDoor);
}