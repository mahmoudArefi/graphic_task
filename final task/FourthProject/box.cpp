#include "box.h"

#include "myTexture.h"

extern  MYTEXTURE myTextureObj ; 
Box::Box(float height, float width, float depth){
	h = height ;
	w = width ;
	d = depth ; 
}

void Box::draw(int typeNum){
	prObj.drawParallelRectangleWithSameTexture(h,w,d,typeNum == 1 ? myTextureObj.box1:myTextureObj.box2,true);
}