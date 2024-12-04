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
}

void MYTEXTURE::InitAllTexture(){
	initComedinaTexture();
	initWardrobeTexture();
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


