#include "kitchen.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>     

#include "myTexture.h"
#include "myPolygon.h"

Kitchen::Kitchen(){}
Kitchen::Kitchen(float height, float width, float depth){
	kH = height ; 
    kW = width ; 
	kD = depth ;
	//manhole varaible 
	manholeH = kH*0.38 ;
	manholeW = kW ;
	manholeD = manholeH ;
	//interface varaiable 
	interfaceD = kD*0.06 ; 
}


void Kitchen::draw(){
    prObj.drawParallelRectangle(kH, kW, kD , TextureType::kitchenRoom);

	glPushMatrix();
	glTranslatef(0,manholeH*0.5 - (kH*0.5),0);
		glPushMatrix();
			glTranslatef(0, 0, -kD*0.5 + manholeD*0.5);
			drawManhole(true);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(manholeD*0.5-kW*0.5, 0 , manholeD*0.5);
			drawManhole(false);
		glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,kD*0.5+ interfaceD*0.5);
		drawInterface();
	glPopMatrix();

}

void Kitchen::drawManhole(bool isType1){
	    //prObj.drawParallelRectangle(kH*0.02, kW, kH*0.02 , TextureType::bathRoom);
	if (isType1) 
        prObj.drawParallelRectangle(manholeH, manholeW, manholeD, TextureType::majla,true);
	else 
		prObj.drawParallelRectangle(manholeH, manholeD, kD-manholeD, TextureType::majla,true);

}

extern  MYTEXTURE myTextureObj  ;
 MYPOLYGON myPolygon ; 
void Kitchen::drawInterface(){
	glPushMatrix();
	float sideW = kW*0.18;
	float centerH = kH*0.5 ; 
	float centerW = kW*0.5 ; 
	float doorW = kW - ((sideW*2)+centerW) ;
	float doorH = kH *0.8 ; 
	glTranslatef(-kW*0.5 + sideW*0.5 , 0 , 0 ) ;

		prObj.drawParallelRectangle(kH, sideW , interfaceD , TextureType::interfaceWall, true);
			glTranslatef( centerW*0.5 + sideW*0.5  ,0,0);
			glPushMatrix();
				glTranslatef(0,centerH*0.5 - kH*0.5,0);
				prObj.drawParallelRectangle(centerH, centerW , interfaceD , TextureType::interfaceWall, true);	

				glPushMatrix();
				glTranslatef(0,kH - centerH*0.5 - kH*0.2 , 0 ) ;
				myPolygon.drawPolygon(kH*0.3,centerW,myTextureObj.glass,0.8);
				glPopMatrix();


					glPushMatrix();
					float topCenterH = kH *0.1 ; 
					glTranslatef(0,kH - centerH*0.5 - topCenterH*0.5 ,0);
							
							prObj.drawParallelRectangle(topCenterH, centerW , interfaceD , TextureType::interfaceWall, true);	
					glPopMatrix();
			glPopMatrix();

				glTranslatef(centerW*0.5 + sideW*0.5 ,0,0) ;
				prObj.drawParallelRectangle(kH, sideW , interfaceD , TextureType::interfaceWall, true);

				glTranslatef(sideW*0.5 + doorW*0.5 ,0 ,0 ) ;
				glPushMatrix();
					glTranslatef(0, -(kH-doorH)*0.5 , 0 ) ;
					glTranslatef(doorW*0.25,0,0) ;
					glRotatef(doorAngle,0,doorW*0.5,0);
					glTranslatef(-doorW*0.25,0,0) ;
					prObj.drawParallelRectangle(doorH, doorW , interfaceD*0.5 , TextureType::interfaceDoor, true);
				glPopMatrix();

					
				glPushMatrix();
				glTranslatef(0, kH*0.5 - (kH-doorH)*0.5 , 0 ) ;
				
				prObj.drawParallelRectangle(kH-doorH, doorW , interfaceD , TextureType::interfaceWall, true);
				glPopMatrix();
				glPopMatrix();


	glPopMatrix();
}

void Kitchen::openAndCloseDoor(bool isOpen){
	if (isOpen && doorAngle>-90){doorAngle-=0.5;}
	else if (!isOpen && doorAngle<0 ) {doorAngle+=0.5;}
}
