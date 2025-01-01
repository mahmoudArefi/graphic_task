#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "parallelRectangle.h"
#include "myPolygon.h"
#include "myTexture.h"

 
class ELEVATOR {
public:
    ELEVATOR(float height , float width , int flooarNumber);  
	void draw() ; 
	void openCloseElevatorDoor(bool isOpenMode);
	void takeElevetorUpOrDown(bool goUp) ; 

private : 
	void drawElevatorDoor(int floorNumber);
 

	float h , w ; 
	int floorNumber ; 
	float oneFloorH ; 


	float topSpaceH  ,
	 theElevatorDoorH ,
	theElevatorDoorW ,
	sideSpace  ,
	currentOpenDoorWidth
	;
	int activeDoor ;
	float activeDoorW ; 

	//elevator high variables 
	float elevatorHigh , minHigh , maxHigh ; 

	
    MYTEXTURE myTextureObj;
    MYPOLYGON myPolygonObj;
	ParallelRectangle parallelRectangle ; 
};



#endif // MYCLASS_H