#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include <vector>
#include "texture.h"
#include "myTexture.h"



MYTEXTURE::MYTEXTURE(){
	comedinaTexture.assign(6, 0);
    staircaseTexture.assign(6, 0);
	wardrobeTexture.assign(6, 0 ); 
	entryRoomTexture.assign(6,0);
	bathRoomTexture.assign(6,0);
	mainRoomTexture.assign(6,0);
	kitchenTexture.assign(6,0);

	//resturnat 
	restuarntTableTexture.assign(6,0);
	resturantChairTexture.assign(6,0);
	artBoard.assign(3,0);
	majlaTexture.assign(6,0);
	kithenInterface.assign(6,0);
	kithenInterfaceDoor.assign(6,0);


	fridgeTexture.assign(6,0);
	pharmacyTexture.assign(6,0);
	
}

void MYTEXTURE::InitAllTexture(){
	initComedinaTexture();
	initWardrobeTexture();
	initEntryRoomTexture();
	initBathRoomTexture();
	initMainRoomTexture();
	initKitchenTexture();
	
	//restuart 
	initResturantTexture();

	//elevator
	elevatorDoor = LoadTexture("textures\\elevatorTexture\\elevatorDoor");

	//pharmcy 
	initPharmcyTexture();
	
	initFridgeTexture();
};

void MYTEXTURE::initFridgeTexture(){
  fridgeDoor = LoadTexture("textures\\fidgeTexture.bmp");
  ovenDoor = LoadTexture("textures\\oven.bmp");
  microDoor = LoadTexture("textures\\microwave.bmp");
  int test = LoadTexture("textures\\OIP.bmp", 255);
  for(int i = 0 ; i<6 ; i++ ){
    fridgeTexture[i] = test;
  }
};

void MYTEXTURE::initComedinaTexture(){
	int drawerSide = LoadTexture("textures\\drawerSide.bmp", 255) ; 
		for(int i = 0 ; i<6 ; i++)
           {staircaseTexture[i] = drawerSide;}
	staircaseTexture[3] = LoadTexture("textures\\drawerFace.bmp", 255);


	for(int i = 0 ; i<6 ; i++ ) {
		comedinaTexture[i] = LoadTexture("textures\\comedinaTexture.bmp", 255); 
	}
};


void MYTEXTURE::initWardrobeTexture(){
	wardrobeDoor = LoadTexture("textures\\wardrobeDoor.bmp");
	 int test = LoadTexture("textures\\drawerSide.bmp", 255);
	for(int i = 0 ; i<6 ; i++ ){
		wardrobeTexture[i] = test ;
	}

};

void MYTEXTURE::initEntryRoomTexture (){
	entryRoomTexture[1] = LoadTexture("textures\\mainRoomWall.bmp"); 
	entryRoomTexture[2] = LoadTexture("textures\\ceiling2.bmp"); 
	entryRoomTexture[3] = LoadTexture("textures\\entryRoomTile.bmp"); 
	entryRoomTexture[4] = LoadTexture("textures\\mainRoomWall.bmp"); 
	entryRoomTexture[5] = LoadTexture("textures\\mainRoomWall.bmp"); 
}

void MYTEXTURE::initBathRoomTexture (){
	bathRoomTexture[1] = LoadTexture("textures\\bathRoomWall.bmp"); 
	bathRoomTexture[2] = LoadTexture("textures\\ceiling.bmp"); 
	bathRoomTexture[3] = LoadTexture("textures\\bathRoomTile.bmp"); 
	bathRoomTexture[4] = LoadTexture("textures\\bathRoomWall.bmp"); 
	bathRoomTexture[5] = LoadTexture("textures\\bathRoomWall.bmp"); 
}

void MYTEXTURE:: initMainRoomTexture(){
	mainRoomTexture[1] = LoadTexture("textures\\mainRoomWall.bmp"); 
	mainRoomTexture[2] = LoadTexture("textures\\ceiling2.bmp"); 
	mainRoomTexture[3] = LoadTexture("textures\\mainRoomTile.bmp"); 
	mainRoomTexture[4] = LoadTexture("textures\\mainRoomWall.bmp"); 
	mainRoomTexture[5] = LoadTexture("textures\\mainRoomWall.bmp"); 
}

void MYTEXTURE:: initKitchenTexture (){
	kitchenTexture[1] = LoadTexture("textures\\kitchenWall.bmp"); 
	kitchenTexture[2] = LoadTexture("textures\\ceiling2.bmp"); 
	kitchenTexture[3] = LoadTexture("textures\\kithenTile.bmp"); 
	kitchenTexture[4] = LoadTexture("textures\\kitchenWall.bmp"); 
	kitchenTexture[5] = LoadTexture("textures\\kitchenWall.bmp"); 
}


void MYTEXTURE::initResturantTexture(){
	resturantChairTexture[0] = LoadTexture("restuarntTexture\\chair_back.bmp"); 
	resturantChairTexture[1] = LoadTexture("restuarntTexture\\chair_back.bmp"); 
	resturantChairTexture[2] = LoadTexture("restuarntTexture\\chair_back.bmp"); 
	resturantChairTexture[3] = LoadTexture("restuarntTexture\\chair_back.bmp"); 
	resturantChairTexture[4] = LoadTexture("restuarntTexture\\chair_back.bmp"); 
	resturantChairTexture[5] = LoadTexture("restuarntTexture\\chair_back.bmp"); 


	restuarntTableTexture[0] = LoadTexture("restuarntTexture\\table.bmp"); 
	restuarntTableTexture[1] = LoadTexture("restuarntTexture\\table.bmp"); 
	restuarntTableTexture[2] = LoadTexture("restuarntTexture\\table.bmp"); 
	restuarntTableTexture[3] = LoadTexture("restuarntTexture\\table.bmp"); 
	restuarntTableTexture[4] = LoadTexture("restuarntTexture\\table.bmp"); 
	restuarntTableTexture[5] = LoadTexture("restuarntTexture\\table.bmp"); 

	artBoard[0] = LoadTexture("restuarntTexture\\art2.bmp");
	artBoard[1] = LoadTexture("restuarntTexture\\art1.bmp");
	artBoard[2] = LoadTexture("restuarntTexture\\art3.bmp");

	//artBoard[0] = LoadTexture("restuarntTexture\\test (1).bmp");
	//artBoard[1] = LoadTexture("restuarntTexture\\test (2).bmp");
	//artBoard[2] = LoadTexture("restuarntTexture\\test (3).bmp");

	restuarntFloor = LoadTexture("restuarntTexture\\restuarnt_floor.bmp"); 
	restuarntRooF = LoadTexture("restuarntTexture\\restuarnt_roof.bmp"); 
	restuarntWall = LoadTexture("restuarntTexture\\restuarnt_wall.bmp"); 



	majlaTexture[0] = LoadTexture("restuarntTexture\\majlaDoors.bmp");
		majlaTexture[1] = LoadTexture("restuarntTexture\\majlaDoors.bmp");
			majlaTexture[2] = LoadTexture("restuarntTexture\\majla.bmp");
				majlaTexture[3] = LoadTexture("restuarntTexture\\majlaDoors.bmp");
					majlaTexture[4] = LoadTexture("restuarntTexture\\majlaDoors.bmp");
						majlaTexture[5] = LoadTexture("restuarntTexture\\majlaDoors.bmp");


	kithenInterface[0] = restuarntWall; 
	kithenInterface[1] = LoadTexture("textures\\kitchenWall.bmp"); 
	kithenInterface[4] = LoadTexture("restuarntTexture\\interfaceWood.bmp"); 
	kithenInterface[5] = LoadTexture("restuarntTexture\\interfaceWood.bmp"); 

	kithenInterfaceDoor[0] = LoadTexture("restuarntTexture\\interfaceDoor.bmp");
	kithenInterfaceDoor[1] = LoadTexture("restuarntTexture\\interfaceDoor.bmp");

	kithenInterfaceDoor[2] = LoadTexture("restuarntTexture\\chair_back.bmp");
	kithenInterfaceDoor[3] = LoadTexture("restuarntTexture\\chair_back.bmp");
	kithenInterfaceDoor[4] = LoadTexture("restuarntTexture\\chair_back.bmp");
	kithenInterfaceDoor[5] = LoadTexture("restuarntTexture\\chair_back.bmp");


	glass = LoadTexture("restuarntTexture\\glass.bmp"); 

}

void MYTEXTURE::initPharmcyTexture(){
		//pharmacy texture
	box1 =LoadTexture("textures\\pharmacyTexture\\woodenBox.bmp"); 
	box2 =LoadTexture("textures\\pharmacyTexture\\cartoonBox.bmp");
	pharmacyTexture[0] = LoadTexture("textures\\pharmacyTexture\\pharmacy_wall.bmp");
	pharmacyTexture[1] = LoadTexture("textures\\pharmacyTexture\\pharmacy_wall.bmp");
	pharmacyTexture[2] = LoadTexture("textures\\pharmacyTexture\\roof.bmp");
	pharmacyTexture[3] = LoadTexture("textures\\pharmacyTexture\\platte.bmp");
	pharmacyTexture[4] = LoadTexture("textures\\pharmacyTexture\\pharmacy_wall.bmp");
	pharmacyTexture[5] = LoadTexture("textures\\pharmacyTexture\\pharmacy_wall.bmp");
	pharmacyLabel =LoadTexture("textures\\pharmacyTexture\\pharmacyPanel.bmp"); 
	pharmacy_wall1 =LoadTexture("textures\\pharmacyTexture\\pharmacyGlass.bmp"); 
	pharmacy_wall2=LoadTexture("textures\\pharmacyTexture\\pharmacy_wall.bmp"); 
	pharmacy_wall3 =LoadTexture("textures\\pharmacyTexture\\wall1.bmp"); 
}