#include "parallelRectangle.h"
#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include "myTexture.h"
#include "table.h"

TABLE::TABLE(){}

void TABLE::draw(float h , float w , float l){
	ParallelRectangle parallelRectangle ; 
	parallelRectangle.drawParallelRectangle(h,w,l,TextureType::comedina,true) ;
    glTranslatef((w/2-h/2), -w/2 - h/2 , l/2 - h/2);
		parallelRectangle.drawParallelRectangle(w,h,h,TextureType::Staircase,true) ;
     glTranslatef(h-w,0 , 0);
	 		parallelRectangle.drawParallelRectangle(w,h,h,TextureType::Staircase,true) ;
      glTranslatef(0,0 , h-l);
	 		parallelRectangle.drawParallelRectangle(w,h,h,TextureType::Staircase,true) ;
     glTranslatef(w-h,0 , 0);
	 		parallelRectangle.drawParallelRectangle(w,h,h,TextureType::Staircase,true) ;
     
}

