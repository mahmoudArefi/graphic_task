
#include "rTable.h"
#include "parallelRectangle.h"
#include "myPolygon.h"
#include "myTexture.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>   


RTable::RTable(){}

//extern 

RTable::RTable(float height, float width, float depth){
	tH = height ; 
    tW = width ; 
	tD = depth ;
}

void RTable::draw(){
	ParallelRectangle prObj ;
	float legW = tD*0.1 , legH = tH*0.65 ; 
	glPushMatrix();
	glTranslatef(0,(legH+legW+legW)-tH,0);

	prObj.drawParallelRectangle(legH, legW, legW ,TextureType::mainRoom,true);

	glPushMatrix();
	 glTranslatef(0,legH*0.5,0);	
		prObj.drawParallelRectangle(legW, tW, tD*0.75 ,TextureType::restuarntTabel,true);
	glPopMatrix();

	glPushMatrix();
	 glTranslatef(0,-legH*0.5,0);	
		prObj.drawParallelRectangle(legW, legW*3, legW*3,TextureType::mainRoom,true);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	 glTranslatef(tW*0.75,0,0);	
			drawChairTable();
	glPopMatrix();


	glPushMatrix();
	 glTranslatef(-tW*0.75,0,0);	
	 glRotatef(180,0,1,0);
			drawChairTable();
	glPopMatrix();


}

void RTable::drawChairTable(){
	ParallelRectangle prObj ;
	float chairSeatH =tH*0.4 , chairSeatW = tW*0.4 ;
	prObj.drawParallelRectangle(tH, tW*0.05, tD,TextureType::resturantChair,true);
	glPushMatrix();
	 glTranslatef(-chairSeatW*0.5,chairSeatH*0.5-tH*0.5,0);	
	 prObj.drawParallelRectangle(chairSeatH, chairSeatW, tD ,TextureType::resturantChair,true);
	glPopMatrix();

}