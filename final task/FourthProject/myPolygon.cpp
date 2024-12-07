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

void MYPOLYGON::drawPolygon(float h, float w, int textureNum) {
    float xOffset = -w * 0.500; // Offset to center the polygon horizontally
    float yOffset = -h * 0.500; // Offset to center the polygon vertically

    if (textureNum == 0) {
        // No texture applied, draw a plain rectangle
        glBegin(GL_QUADS);
        glVertex3f(xOffset, yOffset, 0.0f);                 // Bottom-left
        glVertex3f(xOffset, yOffset + h, 0.0f);            // Top-left
        glVertex3f(xOffset + w, yOffset + h, 0.0f);        // Top-right
        glVertex3f(xOffset + w, yOffset, 0.0f);            // Bottom-right
        glEnd();
    } else {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureNum);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

        // Draw textured rectangle
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(xOffset, yOffset, 0.0f);          // Bottom-left
        glTexCoord2f(0.0f, 1.0f); glVertex3f(xOffset, yOffset + h, 0.0f);      // Top-left
        glTexCoord2f(1.0f, 1.0f); glVertex3f(xOffset + w, yOffset + h, 0.0f);  // Top-right
        glTexCoord2f(1.0f, 0.0f); glVertex3f(xOffset + w, yOffset, 0.0f);      // Bottom-right
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
}
