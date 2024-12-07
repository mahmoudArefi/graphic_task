#include "ParallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include <vector>
#include "texture.h"
#include "myTexture.h"

extern MYTEXTURE myTextureObj ;
extern int SKYLEFT;


ParallelRectangle::ParallelRectangle() {
    // Constructor
}

void ParallelRectangle::drawParallelRectangle(float h, float w, float l, TextureType textureType, bool withFace) {
    float halfW = w / 2.0f; // Half width
    float halfH = h / 2.0f; // Half height
    float halfL = l / 2.0f; // Half length

    std::vector<int> textureList;
    if (textureType != TextureType::null) {
			glEnable(GL_TEXTURE_2D);
        if (textureType == comedina) {
            textureList = myTextureObj.comedinaTexture;
        } else if (textureType == Staircase) {
            textureList = myTextureObj.staircaseTexture;
        } else if (textureType == wardrobe  ){
			textureList = myTextureObj.wardrobeTexture ; 
		}  else if (textureType == entryRoom){
			textureList = myTextureObj.entryRoomTexture ;
		}
		else if (textureType == bathRoom){
			textureList = myTextureObj.bathRoomTexture ;
		}

	else if (textureType == mainRoom){
			textureList = myTextureObj.mainRoomTexture ;
		}
	else if (textureType == kitchenRoom){
			textureList = myTextureObj.kitchenTexture ;
		}

    }


    // Front face (z = +halfL)
    if (withFace) {
        if (textureType != TextureType::null) {
            glBindTexture(GL_TEXTURE_2D, textureList[0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, -halfH, halfL);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(halfW, -halfH, halfL);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, halfH, halfL);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-halfW, halfH, halfL);
            glEnd();
        } else {
            glColor3f(1.0f, 0.0f, 0.0f); // Red color
            glBegin(GL_QUADS);
            glVertex3f(-halfW, -halfH, halfL);
            glVertex3f(halfW, -halfH, halfL);
            glVertex3f(halfW, halfH, halfL);
            glVertex3f(-halfW, halfH, halfL);
            glEnd();
        }
    }

    // Back face (z = -halfL)
    if (textureType != TextureType::null) {
        glBindTexture(GL_TEXTURE_2D, textureList[1]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, -halfH, -halfL);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-halfW, halfH, -halfL);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, halfH, -halfL);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(halfW, -halfH, -halfL);
        glEnd();
    } else {
        glColor3f(0.0f, 1.0f, 0.0f); // Green color
        glBegin(GL_QUADS);
        glVertex3f(-halfW, -halfH, -halfL);
        glVertex3f(-halfW, halfH, -halfL);
        glVertex3f(halfW, halfH, -halfL);
        glVertex3f(halfW, -halfH, -halfL);
        glEnd();
    }

    // Top face (y = +halfH)
    if (textureType != TextureType::null) {
        glBindTexture(GL_TEXTURE_2D, textureList[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, halfH, -halfL);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-halfW, halfH, halfL);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, halfH, halfL);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(halfW, halfH, -halfL);
        glEnd();
    } else {
        glColor3f(0.0f, 0.0f, 1.0f); // Blue color
        glBegin(GL_QUADS);
        glVertex3f(-halfW, halfH, -halfL);
        glVertex3f(-halfW, halfH, halfL);
        glVertex3f(halfW, halfH, halfL);
        glVertex3f(halfW, halfH, -halfL);
        glEnd();
    }

// Bottom face (y = -halfH)
if (textureType != TextureType::null) {
    glBindTexture(GL_TEXTURE_2D, textureList[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, -halfH, -halfL);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(halfW, -halfH, -halfL);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, -halfH, halfL);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-halfW, -halfH, halfL);
    glEnd();
} else {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_QUADS);
    glVertex3f(-halfW, -halfH, -halfL);
    glVertex3f(halfW, -halfH, -halfL);
    glVertex3f(halfW, -halfH, halfL);
    glVertex3f(-halfW, -halfH, halfL);
    glEnd();
}

// Left face (x = -halfW)
if (textureType != TextureType::null) {
    glBindTexture(GL_TEXTURE_2D, textureList[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, -halfH, -halfL);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-halfW, -halfH, halfL);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-halfW, halfH, halfL);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-halfW, halfH, -halfL);
    glEnd();
} else {
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta color
    glBegin(GL_QUADS);
    glVertex3f(-halfW, -halfH, -halfL);
    glVertex3f(-halfW, -halfH, halfL);
    glVertex3f(-halfW, halfH, halfL);
    glVertex3f(-halfW, halfH, -halfL);
    glEnd();
}

// Right face (x = +halfW)
if (textureType != TextureType::null) {
    glBindTexture(GL_TEXTURE_2D, textureList[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(halfW, -halfH, -halfL);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(halfW, halfH, -halfL);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, halfH, halfL);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(halfW, -halfH, halfL);
    glEnd();
} else {
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glBegin(GL_QUADS);
    glVertex3f(halfW, -halfH, -halfL);
    glVertex3f(halfW, halfH, -halfL);
    glVertex3f(halfW, halfH, halfL);
    glVertex3f(halfW, -halfH, halfL);
    glEnd();
}


    if (textureType != TextureType::null) {
			glEnable(GL_TEXTURE_2D);
	}


    glEnd();
}
