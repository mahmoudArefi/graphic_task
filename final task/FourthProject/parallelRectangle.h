#ifndef MYCLASS_H
#define MYCLASS_H
#include <vector>

enum TextureType { comedina, Staircase,wardrobe , entryRoom, bathRoom, mainRoom, kitchenRoom, 
	restuarntTabel , resturantChair , majla , interfaceWall, interfaceDoor ,
	fridge,
	null};

 
 
class ParallelRectangle {
public:
    ParallelRectangle();                 // Constructor 
    void drawParallelRectangle(float h,float w,float l,TextureType textureType = TextureType::null ,  bool withFace = false );       // Method to print a message
	void drawParallelRectangleWithSameTexture(float h,float w,float l, int textureNum ,  bool withFace = false );
	void drawPR(float h,float w,float l, std::vector<int> textureList ,  bool withFace = false );    
};



#endif // MYCLASS_H