#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "camera.h"
#include <fstream>

#include "parallelRectangle.h"
#include "roomWalls.h"
#include "comedina.h"
#include <windows.h>
#include <iostream>
#include "wardrobe.h"
#include "myPolygon.h"
#include "myTexture.h"
#include <cmath>
#include <GL/gl.h>
#include "table.h"
#include "Model_3DS.h"
#include "myModel.h"
#include "sound.h"
#include "Wave.h"
#include "mySounds.h"
#include "elevator.h"
#include <iostream>
#include <float.h>
#include "restaurant.h"
#include "hall.h"
#include "rTable.h"

#include "fridge.h"
#include "microwave.h"
#include "ovenTable.h"
#include "pharmacy.h"

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application



bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default


int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

Camera MyCamera; // عمل اوبجيكت من كلاس الكاميرا
 
// skybox
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;

GLUquadric *quadric = gluNewQuadric();

void drawUnitCube() {

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	//Left Face
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	//Top Face
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}

void drawMyCube(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	drawUnitCube();

	glPopMatrix();

}


void drawMySphere(GLUquadric *quadric, float x, float y, float z, float radius, float xRotate, float yRotate, float zRotate) {

	glPushMatrix();

	glTranslatef(x, y, z);
	glRotatef(zRotate, 0, 0, 1);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(xRotate, 1, 0, 0);
	gluSphere(quadric, radius, 32, 32);

	glPopMatrix();
}

void drawMyCylinder(GLUquadric *quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(zRotate, 0, 0, 1);
	glRotatef(yRotate, 0, 1, 0);
	glRotatef(xRotate, 1, 0, 0);
	gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
	glPopMatrix();
}


void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


}


 WARDROBE wardrobe245 ;
 WARDROBE wardrobe222 ;
 COMEDINA comedina123 ;
 
 
 //extern std::vector<int> staircaseTexture ; 
 //extern std::vector<int> comedinaTexture  ; 
 //extern std::vector<int> wardrobeTexture ; 
 MYTEXTURE myTextureObj ; 

 float x1 = 0 , x2 = 0 , x3 = 0 , x4 = 0 ;


 MYMODEL myModelObj ; 
 MySounds mySoundsObj ;
 Model_3DS *tank ; 
 
 MICROWAVE microwave234 ;
 OVEN_TABLE oven_table1;
 FRIDGE fridge1;


int InitGL(GLvoid) {

    glShadeModel(GL_SMOOTH);
    glClearColor(0.1f, 0.1f, 0.1f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_TEXTURE_2D);



    myTextureObj = MYTEXTURE();
    myTextureObj.InitAllTexture();

    //AllocConsole();
    //freopen("CONOUT$", "w", stdout);
    //freopen("CONIN$", "r", stdin);

    // تحميل خامات السماء
    SKYFRONT = LoadTexture("front.bmp", 255);
    SKYBACK = LoadTexture("back.bmp", 255);
    SKYLEFT = LoadTexture("left.bmp", 255);
    SKYRIGHT = LoadTexture("right.bmp", 255);
    SKYUP = LoadTexture("up.bmp", 255);
    SKYDOWN = LoadTexture("down.bmp", 255);
    glDisable(GL_TEXTURE_2D);



GLfloat Room1LightPos[] = { 12.0f, 5.0f, 10.0f, 0.0f };
GLfloat Room2LightPos[] = { 24.0f, 10.0f, 5.0f, 0.0f };
GLfloat Room3LightPos[] = { -1.0f, 1.0f, 5.0f, 1.0f };
GLfloat Room4LightPos[] = { 10.0f, 5.0f, 10.0f, 0.0f };

    // إعداد خصائص الإضاءة لتجنب مرور الضوء عبر الجدران
    GLfloat LightAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f }; // تقليل الإضاءة المحيطة أكثر
    GLfloat LightDiff[] = { 0.9f, 0.9f, 0.9f, 1.0f }; // زيادة شدة الضوء المنتشر
    GLfloat LightSpec[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // تخفيف اللمعان لجعل الانعكاس أقل حدة


GLfloat MatAmb[] = { 1.0f,0.0f,0.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };

GLfloat MatShn[] = { 128.0f };



    ////// إعداد الضوء لغرفة 3
    ////glEnable(GL_LIGHT2);
    ////glLightfv(GL_LIGHT2, GL_POSITION, Room3LightPos);
    ////glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmb);
    ////glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiff);
    ////glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpec);

    ////// إعداد الضوء لغرفة 4
    ////glEnable(GL_LIGHT3);
    ////glLightfv(GL_LIGHT3, GL_POSITION, Room4LightPos);
    ////glLightfv(GL_LIGHT3, GL_AMBIENT, LightAmb);
    ////glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiff);
    ////glLightfv(GL_LIGHT3, GL_SPECULAR, LightSpec);

    glEnable(GL_COLOR_MATERIAL);

    MyCamera = Camera();
    MyCamera.Position.x = 0;
    MyCamera.Position.y = 0;
    MyCamera.Position.z = 0;

    myModelObj.initAllMyModel();
    mySoundsObj.initAllSounds();

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return TRUE;
}


	ELEVATOR elevator= ELEVATOR(12,3,3) ;


	double shopHeight = 5, shopWidth = 14 , shopDepth = 20 ; 

	Restaurant resturnat  = Restaurant(20,14,20);
	Kitchen kitchenObj = Kitchen(shopHeight,14,20*0.3); 
	RestaurantHall restaurantHallObj = RestaurantHall(shopHeight,14,20*0.7);

	Pharmacy pharmacyObj = Pharmacy(shopHeight,14,20) ;


bool light = false , light1 = false , light2 = false , light3 = false  ;
void light_test(){
	
GLfloat Room1LightPos[] = { 12.0f, 5.0f, 10.0f, 0.0f };
GLfloat Room2LightPos[] = { 24.0f, 10.0f, 5.0f, 0.0f };
GLfloat Room3LightPos[] = { -1.0f, 1.0f, 5.0f, 1.0f };
GLfloat Room4LightPos[] = { 10.0f, 5.0f, 10.0f, 0.0f };

    // إعداد خصائص الإضاءة لتجنب مرور الضوء عبر الجدران
    GLfloat LightAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f }; // تقليل الإضاءة المحيطة أكثر
    GLfloat LightDiff[] = { 0.9f, 0.9f, 0.9f, 1.0f }; // زيادة شدة الضوء المنتشر
    GLfloat LightSpec[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // تخفيف اللمعان لجعل الانعكاس أقل حدة


GLfloat MatAmb[] = { 1.0f,0.0f,0.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };
   
if(light){	    // تفعيل الإضاءة العامة
   glEnable(GL_LIGHTING);

}else{ glDisable(GL_LIGHTING);glDisable(GL_LIGHT0);glDisable(GL_LIGHT1);}

if(light1){
    //// إعداد الضوء لغرفة 1
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, Room1LightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);}
else{
	glDisable(GL_LIGHT0);
}
    //// إعداد الضوء لغرفة 2
if(light2){   glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, Room2LightPos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);}
else{glDisable(GL_LIGHT1);}



if(light3){   glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT1, GL_POSITION, Room3LightPos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);}
else{glDisable(GL_LIGHT2);}




}



void Key(bool* keys, float speed)
{
	if(keys['F']){
		light = true;
	}
	if(keys['G']){
		light1= true ;
	}	if(keys['H']){
		light2= true ;
	}

		if(keys['J']){
		light = false;
	}
	if(keys['K']){
		light1= false ;
	}	if(keys['L']){
		light2= false ;
	}


	if(keys['8']){
		light3= true ;
	}
	if(keys['9']){
		light3= false ;
	}
	



	if(keys['B']){
		kitchenObj.openAndCloseDoor(true);
	}
	if(keys['N']){
		kitchenObj.openAndCloseDoor(false);
	}



	if(keys['B']){
		elevator.takeElevetorUpOrDown(true);
	}
	if(keys['N']){
 
		elevator.takeElevetorUpOrDown(false);
	}

		if(keys['R']){
		elevator.openCloseElevatorDoor(false);
	}
				if(keys['U']){
		elevator.openCloseElevatorDoor(true);
	}


	if (keys['S'])
		MyCamera.RotateX(-6 * speed);
	if (keys['W'])
		MyCamera.RotateX(9* speed);
	if (keys['D'])
		MyCamera.RotateY(-9 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(9* speed);
	if (keys['X'])
		MyCamera.RotateZ(-9 * speed);
	if (keys['A'])
		MyCamera.RotateY(6 * speed);
	if (keys[VK_UP])
		MyCamera.MoveForward(9 * speed);
	if (keys[VK_DOWN])
		MyCamera.MoveForward(-9 * speed);
	if (keys[VK_RIGHT])
		MyCamera.MoveRight(9 * speed);
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-9 * speed);
	if (keys['O'])
		MyCamera.MoveUpward(4 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-4 * speed);
	if (keys['0'])
		wardrobe222.openOrCloseDoors(true) ; 
	if (keys['9'])
		wardrobe222.openOrCloseDoors(false) ; 


	if (keys['1']){
		mySoundsObj.testSound.Sound.Play(0);
		comedina123.openOrCloseStaircase(1,keys['Q']);
	}
	if (keys['2'])
		comedina123.openOrCloseStaircase(2,keys['Q']);
	if (keys['3'])
		comedina123.openOrCloseStaircase(3,keys['Q']);
	

				if(keys['q']||keys['Q'])
				//comedina123.openOrCloseStaircase(0) ;


					if(keys['4'])
				microwave234.openCloseDoor(1) ;
					if(keys['5'])
					{
						std::cout<<"test open and close state " ;
						microwave234.openCloseDoor(0) ;
					}

						if(keys['6'])
					{
						oven_table1.openCloseDoor(0) ;
					}
						
						if(keys['7'])
					{
						oven_table1.openCloseDoor(1) ;
					}
	
}

 
 
 
RoomWalls roomWalls ; 

 
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red with 50% transparency
//
//    glBegin(GL_POLYGON);
//        glVertex3f(-0.5f, -0.5f, 0.0f);
//        glVertex3f( 0.5f, -0.5f, 0.0f);
//        glVertex3f( 0.5f,  0.5f, 0.0f);
//        glVertex3f(-0.5f,  0.5f, 0.0f);
//    glEnd();
//
//    glDisable(GL_BLEND);
//
//    glutSwapBuffers();
//}

 
ParallelRectangle prObj ;

void drawTransparentPolygon() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red color with 50% transparency
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();

    glDisable(GL_BLEND);
}

void drawTexturedTransparentPolygon(GLuint texture) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // 50% transparency
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}



int DrawGLScene(GLvoid) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    MyCamera.Render(); // Apply camera transformations
    Key(keys, 0.05);

	//std::cout<<light << "    " << light1 << "    " << light2 << std::endl ;
	//glTranslatef(+11,-1,-25);  // resturant transfer
	

    //roomWalls.drawHouse();
	//display();
	
	//glTranslatef(0,0,-14);
	pharmacyObj.draw();

	glTranslatef(20,0,-shopDepth*0.5 );
	//glTranslatef(20 , 0 , 0 ) ;
	resturnat.draw();

	//drawTransparentPolygon();
	/*drawTexturedTransparentPolygon(myTextureObj.artBoard[0]);
	glTranslatef(0,0,5);
	drawTexturedTransparentPolygon(myTextureObj.artBoard[1]);*/
	light_test();
			
	//glTranslatef(-(8+1.5 + 0.5) , -2 + 12/3 , 1 ) ;
	//elevator.draw();
	

    return TRUE;
}


GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}


LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{

		case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

