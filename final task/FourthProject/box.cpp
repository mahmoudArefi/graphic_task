#include "box.h"


Box::Box(float height, float width, float depth){
	h = height ;
	w = width ;
	d = depth ; 
}

void Box::draw(){
	prObj.drawParallelRectangle(h,w,d,TextureType::entryRoom,true);
}