#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include <vector>
#include "texture.h"
#include "myPolygon.h"


MYPOLYGON::MYPOLYGON(){} 

void MYPOLYGON::drawPolygon(float x, float y , float h , float w ,int textureNum ) {
	if(textureNum==0){
	}
	else{
 	glEnable(GL_TEXTURE_2D);
 glBindTexture(GL_TEXTURE_2D, textureNum);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

    // Draw rectangle
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, 0.0f);                  // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + h, 0.0f);        // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x + w, y + h, 0.0f); // Top-left
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x + w, y, 0.0f);         // Bottom-left
    glEnd();
	}
}