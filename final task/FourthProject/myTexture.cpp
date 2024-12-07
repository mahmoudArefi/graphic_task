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
}

void MYTEXTURE::InitAllTexture(){
	initComedinaTexture();
	initWardrobeTexture();
	initEntryRoomTexture();
	initBathRoomTexture();
	initMainRoomTexture();
	initKitchenTexture();
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


