#include "elevator.h"
#include "parallelRectangle.h"
#include "myPolygon.h"
#include "myTexture.h"

#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library

#include <iostream>


ELEVATOR::ELEVATOR(float height , float width , int flooarNumber){
	h = height ; 
	w = width ;
	floorNumber = flooarNumber ; 
	oneFloorH = height/flooarNumber * 1  ;

   topSpaceH = oneFloorH * 0.2 ; 
   theElevatorDoorH = oneFloorH - topSpaceH ;
   theElevatorDoorW = w * 0.35; 
   sideSpace = w*0.5 - theElevatorDoorW  ; 

   currentOpenDoorWidth = theElevatorDoorW; 
   elevatorHigh = oneFloorH*0.5-h*0.5 ;
   minHigh = elevatorHigh ; 
   maxHigh = h*0.5 - oneFloorH*0.5;
   activeDoor = 1 ;
   activeDoorW = theElevatorDoorW ; 
   myPolygonObj = MYPOLYGON();
   myTextureObj = MYTEXTURE ();
   parallelRectangle = ParallelRectangle();
}

void ELEVATOR::draw() {
    // The elevator border
    glPushMatrix();
    parallelRectangle.drawParallelRectangle(h, w, w, TextureType::mainRoom);
    glPopMatrix();

    // The elevator body (the small room which goes up and down)
    glPushMatrix();
	//std::cout<< "test "  << elevatorHigh << std::endl;
    glTranslatef(0, elevatorHigh , 0);
    parallelRectangle.drawParallelRectangle(oneFloorH, w * 0.98, w * 0.98, TextureType::bathRoom);
    glPopMatrix();
    // Elevator doors
    glPushMatrix();
    glTranslatef(0, -oneFloorH, w * 0.5);
    for (int i = 0; i < floorNumber; i++) {
        glPushMatrix();
        glTranslatef(0, i * oneFloorH, 0);
        drawElevatorDoor(i+1);
        glPopMatrix();
    }
    glPopMatrix();
}



void ELEVATOR::drawElevatorDoor(int floorNumber){
    // Draw topSpace 
    glPushMatrix();
	glTranslatef(0, oneFloorH*0.5 - topSpaceH*0.5  , 0);
    myPolygonObj.drawPolygon(topSpaceH, w );
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, -topSpaceH*0.5, 0);
    // Draw side space on right  
    glPushMatrix();
    glTranslatef(w * 0.5 - sideSpace*0.5,  0, 0);
    myPolygonObj.drawPolygon(theElevatorDoorH,sideSpace);
    glPopMatrix();
 
    // Draw side space on left
    glPushMatrix();
    glTranslatef(sideSpace*0.5- w * 0.5  , 0 , 0);
    myPolygonObj.drawPolygon(theElevatorDoorH,sideSpace);
    glPopMatrix();

	float doorWidth =  (floorNumber==activeDoor) ? activeDoorW : theElevatorDoorW  ;
	glPushMatrix();
	glTranslatef(0,0,-0.1);
	// Draw rightDoor 
    glPushMatrix();
    glTranslatef((w * 0.5 - (theElevatorDoorW*0.5 + sideSpace)) + (floorNumber==activeDoor? theElevatorDoorW - doorWidth :0) ,0, 0);
	myPolygonObj.drawPolygon(theElevatorDoorH,doorWidth,1);
    glPopMatrix();
 
    // Draw leftDoor
    glPushMatrix();
	//glTranslatef((w * 0.5 - (theElevatorDoorW*0.5 + sideSpace)) - (floorNumber==activeDoor? theElevatorDoorW - doorWidth :0) ,0, 0);
    glTranslatef( (theElevatorDoorW*0.5 + sideSpace) -w * 0.5 - (floorNumber==activeDoor? theElevatorDoorW - doorWidth :0) , 0, 0);
    myPolygonObj.drawPolygon(theElevatorDoorH,doorWidth,1);
    glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

void ELEVATOR::openCloseElevatorDoor(bool isOpen){
	if(isOpen && activeDoorW > w*0.1 ) {activeDoorW-=0.1;}
	else if(isOpen==false && activeDoorW < theElevatorDoorW) {activeDoorW+=0.1;}

}

void ELEVATOR::takeElevetorUpOrDown(bool isUp) {
	 
	if(isUp && elevatorHigh<maxHigh){
		elevatorHigh+=0.1 ; 
        std::cout<< elevatorHigh << std::endl;
	}
	if (isUp == false && elevatorHigh>minHigh){
		elevatorHigh-=0.1 ; 
        std::cout<< elevatorHigh << std::endl;
	}
	int oldValueOfActiveDoor = activeDoor ;
	//std::cout<< "current value of elevatorHigh "<<  elevatorHigh << "that mean the active door will be ( " <<  (elevatorHigh+h/2 + minHigh/2) /  (oneFloorH) << "  ) " << std::endl ;
	activeDoor = (elevatorHigh+h/2 + minHigh/2) /  (oneFloorH) + 1 ; ///this line which you have to work on 
	//std::cout<<"active door " << activeDoor << std::endl ;
	if ( oldValueOfActiveDoor != activeDoor  ) {activeDoorW = theElevatorDoorW;}
	if(activeDoorW>theElevatorDoorW){activeDoorW+=0.5;}
}


