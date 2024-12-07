#ifndef MYCLASS_H
#define MYCLASS_H
#include <vector>

enum TextureType { comedina, Staircase,wardrobe , entryRoom, bathRoom, mainRoom, kitchenRoom,  null};

 
 
class ParallelRectangle {
public:
    ParallelRectangle();                 // Constructor 
    void drawParallelRectangle(float h,float w,float l,TextureType textureType = TextureType::null ,  bool withFace = false);       // Method to print a message

};



#endif // MYCLASS_H