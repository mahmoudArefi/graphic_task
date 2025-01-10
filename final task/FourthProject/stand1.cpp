#include "stand1.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>   

Stand1::Stand1(float height, float width, float depth){
	sH = height ; 
	sW = width  ; 
	sD = depth  ;
}

void Stand1::draw(){
	prObj.drawParallelRectangle(sH,sW,sD,TextureType::bathRoom);

	glTranslatef(0,-sH*0.5,0);

	for(int i = 0 ; i<=3 ; i++ ) {
		glPushMatrix();
		glTranslatef(0,sH/4 * i , 0 ) ;
		prObj.drawParallelRectangle(0.1,sW,sD,TextureType::mainRoom,true);
		glPopMatrix();
	}
	
	
}