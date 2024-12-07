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

	parallelRectangle.drawParallelRectangle(h*0.15,w,l,TextureType::comedina,true) ;

	float legH = h *0.85 ; 
	float legWL = w *0.14;

    glTranslatef(-(w/2-legWL/2) , -(legH/2 +(h*0.15/2)), l/2 -legWL/2);
		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
    glTranslatef(w-legWL,0,0);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
      glTranslatef(0,0 , legWL-l);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
     glTranslatef(legWL-w,0 , 0);
	 		parallelRectangle.drawParallelRectangle(legH,legWL,legWL,TextureType::Staircase,true) ;
     
}

