#include "roomWalls.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>

RoomWalls::RoomWalls() {
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

void RoomWalls::drawHouse(){
	float roomHeight = 4 , roomWidth = 2 , roomDepth =  2 ; 
	glPushMatrix();
	glTranslatef( -roomWidth*1.2 , roomHeight*0.5 , 0.0f);
	drawRoomWalls(roomHeight,roomWidth,roomDepth) ;
	glPopMatrix();

	glPushMatrix();
	glTranslatef( roomWidth*1.2 , roomHeight*0.5 , 0.0f);
	drawRoomWalls(roomHeight,roomWidth,roomDepth) ;
	glPopMatrix();


	glPushMatrix();
	glTranslatef( roomWidth*1.2 , -roomHeight*0.02 , 0.0f);
	drawRoomWalls(roomHeight,roomWidth,roomDepth) ;
	glPopMatrix();

	glPushMatrix();
	glTranslatef( -roomWidth*1.2 , -roomHeight*0.02, 0.0f);
	drawRoomWalls(roomHeight,roomWidth,roomDepth) ;
	glPopMatrix();
}




