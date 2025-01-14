#include "hall.h"
#include "parallelRectangle.h"
#include "myPolygon.h"
#include "myTexture.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>   

#include "rTable.h"
#include "myModel.h"

RestaurantHall::RestaurantHall(float height, float width, float depth){
	hH = height ; 
    hW = width ; 
	hD = depth ;
}

extern  MYTEXTURE myTextureObj  ;
extern ParallelRectangle prObj ;
extern  MYMODEL myModelObj ; 
MYPOLYGON myPolgonObj = MYPOLYGON();



void casherTable(float halfH,float halfW, float halfD){
		
		
		glTranslatef(0,0,halfD*2);
		prObj.drawParallelRectangle(halfH*1.5, halfW*2, halfD*0.1 ,TextureType::mainRoom,true);
			
		
		 glTranslatef(0,-halfH*0.25,halfD*0.5);	
		 prObj.drawParallelRectangle(halfH, halfW*2 , halfD ,TextureType::mainRoom,true);	
}

void drawChair(float halfH,float halfW, float halfD ){
		
		float legW = halfW*0.2 ; 
		
	    //draw legs 
		 for(int i = 1 ; i<=4 ; i++){
			 glPushMatrix();
			 glTranslatef(i%2==0?halfW : -halfW ,0,i>2?halfD:-halfD);
				 prObj.drawParallelRectangle(halfH,legW,legW,TextureType::mainRoom,true);
			 glPopMatrix();
		 }
		 //draw chair seat 
		 glTranslatef(0,halfH*0.5,0);
		 prObj.drawParallelRectangle(halfH*0.05,halfW*2+legW,halfD*2+legW,TextureType::mainRoom,true);

		 //draw chair back 
		 glTranslatef(-halfW,halfH*0.5,0);
		 prObj.drawParallelRectangle(halfH,legW,halfD*2+legW,TextureType::mainRoom,true);
}
	
void RestaurantHall::draw(){
	glRotatef(90,1,0,0);
		glPushMatrix();
			glTranslatef(0,0,-hH*0.5);
			 myPolgonObj.drawPolygon(hD,hW,myTextureObj.restuarntRooF);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,hH*0.5);
			 myPolgonObj.drawPolygon(hD,hW,myTextureObj.restuarntFloor);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(hW*0.5,0,0);
			glRotatef(90,0,1,0);
			glPushMatrix();
			glTranslatef(0,-hW*0.25,0);
			for(int i = 0; i<=2 ; i++){
					glPushMatrix();
						glTranslatef(hH*0.25,hW/4 * i ,-0.1);
						glRotatef(-90,0,0,1);
						 myPolgonObj.drawPolygon(hW*0.1,hW*0.1,myTextureObj.artBoard[i]);
					glPopMatrix();
			}
			glPopMatrix();
				 myPolgonObj.drawPolygon(hD,hH,myTextureObj.restuarntWall);
		glPopMatrix();

		/*glPushMatrix();
			glTranslatef(-hW*0.5-0.1,0,0);
			glRotatef(90,0,1,0);
				 myPolgonObj.drawPolygon(hD,hH,myTextureObj.restuarntWall);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(0,hD*0.5,0);
			glRotatef(90,1,0,0);
				 myPolgonObj.drawPolygon(hH,hW,myTextureObj.restuarntWall);
		glPopMatrix();*/

		




		float chairFactor = 2 ; 
		//drawing the chairs next to windows

		glPushMatrix();
			glTranslatef( chairFactor*0.5-hW*0.5  ,-(hH+chairFactor*0.5),   hH *0.5 - chairFactor*0.5);
			glRotatef(-90,1,0,0);
			glRotatef(-90,0,1,0);

		for(int i=0;i<4	;i++){
			glPushMatrix();
			glTranslatef(i*chairFactor *1.5 ,0,0);
			RTable rTable = RTable(2, 2,2 ) ;
			rTable.draw();
			glPopMatrix();
		}


		glPushMatrix();
		glTranslatef(0,0,-hW*0.4);

		for(int i=0;i<4	;i++){
			glPushMatrix();
			glTranslatef(i*chairFactor *1.5 ,0,0);
			myModelObj.table->model->Draw();
			glPopMatrix();
		}

		glPopMatrix();
		
		

		glPushMatrix();
		glTranslatef(0,0,2-hW);

		for(int i=0;i<3	;i++){
			if(i==0){continue;}
			glPushMatrix();
			glTranslatef(i*chairFactor *1.5 ,0,0);
			RTable rTable = RTable(2, 2,2 ) ;
			rTable.draw();
			glPopMatrix();
		}



		
		////draw casher table 
		float halfH=1  , halfW=1 , halfD=0.5 ; 
		glTranslatef(hD - halfW*3,0,1);

		glPushMatrix();
		glRotatef(180,0,1,0);
				//glTranslatef(0,0,halfD*2);
		prObj.drawParallelRectangle(halfH*1.5, halfW*2, halfD*0.1 ,TextureType::resturantChair,true);
		 glTranslatef(0,-halfH*0.25,halfD*0.5);	
		 prObj.drawParallelRectangle(halfH, halfW*2 , halfD ,TextureType::resturantChair,true);	



		 glTranslatef(0,0,halfD*2);
		 ////draw casher chare 
		 glPushMatrix();
		 glRotatef(90,0,1,0);
		 //glTranslatef(0,0,2);
		 halfH=0.65  , halfW=0.5 , halfD=0.5 ; 
		 float legW = halfW*0.2 ; 
		
	    //draw legs 
		 for(int i = 1 ; i<=4 ; i++){
			 glPushMatrix();
			 glTranslatef(i%2==0?halfW : -halfW ,0,i>2?halfD:-halfD);
				 prObj.drawParallelRectangle(halfH,legW,legW,TextureType::restuarntTabel,true);
			 glPopMatrix();
		 }
		 //draw chair seat 
		 glTranslatef(0,halfH*0.5,0);
		 prObj.drawParallelRectangle(halfH*0.05,halfW*2+legW,halfD*2+legW,TextureType::restuarntTabel,true);

		 //draw chair back 
		 glTranslatef(-halfW,halfH*0.5,0);
		 prObj.drawParallelRectangle(halfH,legW,halfD*2+legW,TextureType::restuarntTabel,true);
		 glPopMatrix();

		glPopMatrix();

		glPopMatrix();


		glPopMatrix();

}


