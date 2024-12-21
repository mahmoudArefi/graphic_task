#include <iostream>
#include <windows.h>        // Header File For Windows
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>          // Header File For The Glaux Library
#include <cmath>
#include "myModel.h"
#include "modelClass.h"

 MYMODEL::MYMODEL(){};

 void MYMODEL::initAllMyModel()
 {
	 initTank();
	 initTree();
	 initTable();
	 initBed();
	 initWoodTable();
 }

 void MYMODEL::initTank(){
	tank = new Model_3DS() ;
	tank-> Load("myModels\\tank\\tank.3DS") ;
	tank->pos.x=0;
	tank->pos.y=-10;
	tank->pos.z=-9;
	tank->scale=1;
 }


void MYMODEL::initTable(){
    GLTexture modelTexture;
	Model_3DS* myModel = new Model_3DS();  // Changed to ModelVar class
    myModel->Load("myModels\\table\\A032.3ds");
    modelTexture.LoadBMP("myModels\\table\\t1.bmp");
    myModel->Materials[0].tex = modelTexture;
    myModel->Materials[1].tex = modelTexture;
	
	//table = ModelVar(myModel,0.05,1.0,1.0,1.0) ;
    table = new ModelVar(myModel, 0.005, 574.131, 601.621 ,348.917 );

}


 void MYMODEL::initTree(){

	 GLTexture BARK,Leaf;
	 	tree = new Model_3DS();
tree->Load("myModels\\Tree Model\\Tree1.3DS");
Leaf.LoadBMP("myModels\\Tree Model\\bat.bmp");
BARK.LoadBMP("myModels\\Tree Model\\bark_loo.bmp");


tree->Materials[0].tex=BARK;
tree->Materials[1].tex=Leaf;
tree->Materials[2].tex=Leaf;
tree->Materials[3].tex=Leaf;
tree->Materials[4].tex=Leaf;


tree->pos.x=0;
tree->pos.y=0;
tree->pos.z=0;
tree->scale=1;
 }

 void MYMODEL::initBed(){
	
	Model_3DS* myModel = new Model_3DS();  // Changed to ModelVar class

	
    myModel->Load("myModels\\bed\\Bed.3ds");

	GLTexture t1, t2 , t3 , t4 ;
	t1.LoadBMP("myModels\\bed\\Bed Sh.bmp");
	t2.LoadBMP("myModels\\bed\\Bed Sh1.bmp");
	t3.LoadBMP("myModels\\bed\\seamless-wood-texture-free-22.bmp");
	t4.LoadBMP("myModels\\bed\\light-wood-texture 1.bmp");

    myModel->Materials[0].tex = t1;
    myModel->Materials[1].tex = t2;
    myModel->Materials[2].tex = t4;
	myModel->Materials[3].tex = t4; //head of the bed
    myModel->Materials[4].tex = t1;
    myModel->Materials[5].tex = t2;
	myModel->Materials[6].tex = t1; // sharfaf 

	//modelTexture.LoadBMP("myModels\\bed\\light-wood-texture 1.bmp");
 //   myModel->Materials[3].tex = modelTexture;

    //modelTexture.LoadBMP("myModels\\table\\t1.bmp");
	bed = new ModelVar(myModel,0.004 ,291 , 589 , 857) ;
 }


 void MYMODEL::initWoodTable(){
    GLTexture modelTexture;
	Model_3DS* myModel = new Model_3DS();  // Changed to ModelVar class
    myModel->Load("myModels\\Wood Table with glasplatte\\Wood_Table.3ds");
    modelTexture.LoadBMP("myModels\\Wood Table with glasplatte\\textures\\Wood_Table_C.bmp");
    myModel->Materials[0].tex = modelTexture;
    myModel->Materials[1].tex = modelTexture;
	
	//table = ModelVar(myModel,0.05,1.0,1.0,1.0) ;
    woodTable = new ModelVar(myModel, 1.5, 0.466 , 0.66 , 0.66 );

}


