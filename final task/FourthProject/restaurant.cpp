#include "restaurant.h"
#include "parallelRectangle.h"

#include <windows.h>    
#include <gl.h>             // Header File For The OpenGL32 Library
#include <glu.h>            // Header File For The GLu32 Library
#include <glaux.h>   


#include "kitchen.h"
#include "hall.h"


Restaurant::Restaurant(float height, float width, float depth){

	
	rH = height ; 
	rW = width ; 
	rD = depth ;
    prObj = ParallelRectangle();
   

}

	extern Kitchen kitchenObj ; 
	extern RestaurantHall restaurantHallObj ; 

void Restaurant::draw(){
	kitchenObj.draw();
	glTranslatef(0,0,rD*0.5);
	restaurantHallObj.draw();
}


 


void Restaurant::drawResturnSallon(){}

