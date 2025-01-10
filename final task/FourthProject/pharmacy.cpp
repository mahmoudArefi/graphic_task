
#include "pharmacy.h"
#include "parallelRectangle.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>   

#include "stand1.h"
#include "box.h"
#include "myPolygon.h"
#include "myTexture.h"
Pharmacy::Pharmacy(float height, float width, float depth){
	pH = height ; 
	pW = width ; 
	pD = depth ; 
}
 
extern  MYTEXTURE myTextureObj ; 
void Pharmacy::draw() {
    prObj.drawParallelRectangle(pH, pW, pD, TextureType::mainRoom);

    glPushMatrix();
    glTranslatef(pW * 0.5, -pH * 0.5, -pD * 0.5);
    drawStoreHouse();
    glPopMatrix();

	glPushMatrix();
    drawWallBetweenWareHouseAndPharmacy();
    glTranslatef(0, 0, pD * 0.1);

   drawPharmacyMeanPart();
   glPopMatrix();
   
   float labelH = pH*0.15 , topPartH = pH*0.22 , sidePartW = pW*0.4 ;
	glPushMatrix();
	glTranslated(0,pH*0.5,pD*0.5);
	MYPOLYGON polygonObj = MYPOLYGON();
	glTranslated(0,-labelH*0.5, 0);
	polygonObj.drawPolygon(labelH, pW , myTextureObj.artBoard[1]  ) ;
	glTranslated(0,-(labelH+topPartH)*0.5,0);
	polygonObj.drawPolygon(topPartH,	pW , myTextureObj.artBoard[1]  ) ;
	glTranslated((pW-sidePartW)*0.5, topPartH - (pH-(labelH+topPartH)) , 0);
	polygonObj.drawPolygon(pH - ( labelH+topPartH) ,	sidePartW  , myTextureObj.artBoard[1] , 0.5  ) ;
	glTranslated(-pW*0.5-sidePartW*0.25,0,0);
	polygonObj.drawPolygon(pH - ( labelH+topPartH) ,	sidePartW  , myTextureObj.artBoard[1]  ) ;
	
	glPopMatrix();
}


void Pharmacy::drawPharmacyMeanPart(){
	    float standH = pH * 0.95, standW = pW * 0.125, standD = pD * 0.06;
    glTranslatef(pW * 0.5 - standW * 1.5, 0, 0);
    Stand1 stand = Stand1(standH, standW, standD);
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(-(standW * i + i*0.2), 0, 0);
        stand.draw();
        glPopMatrix();
    }

	Stand1 stand2 = Stand1(standH, pW*0.4, standD);
	glPushMatrix();
	glTranslatef(standD*2-pW,0,pD*0.25);
	glRotatef(90,0,1,0);
	
	stand2.draw();
	glPopMatrix();

	

    float cashTableH = pH * 0.28, cashTableW = pW * 0.75, cashTableD = pD * 0.1;
    glPushMatrix();
    glTranslatef((cashTableW-pW)-0.5, cashTableH*0.5 -pH * 0.5, cashTableD);
    prObj.drawParallelRectangle(cashTableH, cashTableW, cashTableD, TextureType::interfaceDoor, true);

	glTranslatef(cashTableD*0.5-cashTableW*0.5,0,cashTableH+cashTableD);
	glRotatef(90,0,1,0);
	prObj.drawParallelRectangle(cashTableH, cashTableW*0.5, cashTableD, TextureType::wardrobe, true);
    glPopMatrix();

	



}





void Pharmacy::drawStoreHouse() {
    float boxH = pH * 0.15, boxW = pW * 0.1, boxD = pD * 0.08;
    float boxH2 = pH * 0.25, boxW2 = pW * 0.08, boxD2 = pD * 0.08;
    Box box1 = Box(boxH, boxW, boxD);
    Box box2 = Box(boxH2, boxW2, boxD2);

    glPushMatrix(); // Start main matrix stack
    glTranslatef(-boxW * 0.5, boxH * 0.5, boxD * 0.5);

    // Draw first set of objects (box1)
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < 6 - t; i++) {
            glPushMatrix();
            glTranslatef(0, boxH * i + 0.05, 0);
            box1.draw();
            glPopMatrix();
        }
        glTranslatef(0, 0, boxD * 1.1); // Move along the z-axis
    }
    glPopMatrix(); // End of box1 transformations

    // Start drawing 4 objects (box2)
    glPushMatrix();
    glTranslatef(-boxW, boxH2 * 0.25, 0);

    for (int u = 1; u <= 4; u++) {
        glPushMatrix(); // Save the current matrix state

        // Apply extra padding to the 3rd and 4th objects
        int help = (u >= 3) ? pD * 0.3 : 0.1;
        glTranslatef(0, 0, boxD + help);

        // Draw boxes in this object
        for (int x = 0; x < 7; x++) {
            int test = (x < 5 && x >= 2) ? 3 : 2;
            for (int i = 0; i < test; i++) {
                glPushMatrix();
                glTranslatef(0, boxH2 * i - 0.08, 0); // Stack along y-axis
                box2.draw();
                glPopMatrix();
            }
            glTranslatef(-boxW2 - 0.1, 0, 0); // Move along x-axis
        }
        glPopMatrix(); // Restore matrix state for the next object
    }

    // Cleanup after all 4 objects
    glPopMatrix(); // End main transformation
}

void Pharmacy::drawWallBetweenWareHouseAndPharmacy(){
	glTranslatef(pW*0.1,0,-1.5);
	prObj.drawParallelRectangle(pH , pW*0.8 , 1,TextureType::wardrobe,true) ;
}