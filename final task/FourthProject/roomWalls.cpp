#include "roomWalls.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include "parallelRectangle.h"
#include "comedina.h"
#include "wardrobe.h"
#include "table.h"
RoomWalls::RoomWalls() {
     roomHeight = 4;
	 roomWidth = 8;
	 roomDepth =4;
    // Constructor
}

void RoomWalls::drawRoomWalls(float h, float w, float l) {

	glRotatef(90, 0.0f, 0.0f, 1.0f);  
    float halfW = w / 2.0f; // Half width
    float halfH = h / 2.0f; // Half height
    float halfL = l / 2.0f; // Half length
	float myFactor = 1.2f ; 
    glBegin(GL_QUADS); // Begin drawing the parallelepiped

  // // Front face (z = +halfL)
  // glColor3f(1.0f, 0.0f, 0.0f); // Red color
  // glVertex3f(-halfW, -halfH, halfL);
  // glVertex3f(halfW, -halfH, halfL);
  // glVertex3f(halfW, halfH, halfL);
  // glVertex3f(-halfW, halfH, halfL);

    // Back face (z = -halfL)
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex3f(-halfW, -halfH, -halfL);
    glVertex3f(-halfW, halfH, -halfL);
    glVertex3f(halfW, halfH, -halfL);
    glVertex3f(halfW, -halfH, -halfL);

    // Top face (y = +halfH)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex3f(-halfW, halfH, -halfL);
    glVertex3f(-halfW, halfH*myFactor , halfL);
    glVertex3f(halfW , halfH*myFactor, halfL);
    glVertex3f(halfW , halfH, -halfL);

    // Bottom face (y = -halfH)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex3f(-halfW, -halfH, -halfL);
    glVertex3f(halfW, -halfH, -halfL);
    glVertex3f(halfW, -halfH*myFactor, halfL);
    glVertex3f(-halfW, -halfH*myFactor, halfL);

    // Right face (x = +halfW)
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta color
    glVertex3f(halfW, -halfH, -halfL);
    glVertex3f(halfW, halfH, -halfL);
    glVertex3f(halfW, halfH * myFactor, halfL);
    glVertex3f(halfW, -halfH*myFactor, halfL);

    // Left face (x = -halfW)
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glVertex3f(-halfW, -halfH, -halfL);
    glVertex3f(-halfW, -halfH*myFactor, halfL);
    glVertex3f(-halfW, halfH*myFactor, halfL);
    glVertex3f(-halfW, halfH, -halfL);

    glEnd(); // End drawing the parallelepiped
}

void RoomWalls::drawHouse() {
  
	 ParallelRectangle prObj = ParallelRectangle();
    // Top-left rectangle
    glPushMatrix();
    glTranslatef(-roomWidth*0.505, roomHeight * 0.505, 0.0f); // Top position (y positive)
    prObj.drawParallelRectangle(roomHeight, roomWidth, roomDepth , TextureType::mainRoom);
    glPopMatrix();

    // Top-right rectangle
    glPushMatrix();
    glTranslatef(roomWidth*0.505 , roomHeight * 0.505, 0.0f); // Top position (y positive)
    prObj.drawParallelRectangle(roomHeight, roomWidth, roomDepth, TextureType::kitchenRoom);
    glPopMatrix();

    // Bottom-right rectangle
    drawEntryRoom();

    // Bottom-left rectangle
    glPushMatrix();
    glTranslatef(-roomWidth*0.505 , -roomHeight * 0.505, 0.0f); // Bottom position (y negative)
    prObj.drawParallelRectangle(roomHeight, roomWidth, roomDepth, TextureType::bathRoom);
    glPopMatrix();
}

void RoomWalls::drawEntryRoom(){
	 ParallelRectangle prObj = ParallelRectangle();
	extern  COMEDINA comedina123 ;
	float comedinaH = roomHeight*0.25;
	float comedinaW = roomWidth *0.15 ;
	float comedinaD = roomDepth * 0.4 ;

	extern  WARDROBE wardrobe222 ;
	float warddropH = roomHeight*0.6	;
	float wardropeW = roomWidth *0.4;
	float wardropeD = roomDepth * 0.4;

	TABLE table ; 
	float tableH = roomHeight*0.2;
	float tableW = roomWidth*0.1;
	float tableD = roomDepth* 0.4;

	//std::cout<< " H : " << warddropH << "    W : " << wardropeW << "     D :  " << wardropeD ; 
	glPushMatrix();
    glTranslatef(roomWidth*0.505, -roomHeight * 0.505, 0.0f); // Bottom position (y negative)
    prObj.drawParallelRectangle(roomHeight, roomWidth, roomDepth, TextureType::entryRoom);

	glTranslatef(0,comedinaH/2-(roomHeight*0.5),comedinaD/2-(roomDepth*0.5));

	glTranslatef(roomWidth*0.24,0,0);
    comedina123.draw(comedinaH, comedinaW ,comedinaD);
	

	glTranslatef(-roomWidth*0.2,tableH/2,0);
    table.draw(tableH, tableW ,tableD);
	glPopMatrix();
 

	glPushMatrix();
	glTranslatef((roomWidth/2-wardropeW/2)*0.9   ,-roomHeight/2 - warddropH/2,    wardropeD/2-roomDepth/2 );
	wardrobe222.draw(warddropH, wardropeW ,wardropeD);
	 /*glTranslatef(-wardropeW, 0  ,   wardropeD);
     wardrobe222.draw(warddropH, wardropeW ,wardropeD);
	 glPopMatrix();*/
	    


    glPopMatrix();
}





