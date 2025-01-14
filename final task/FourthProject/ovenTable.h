#ifndef OVEN_TABLE_H
#define OVEN_TABLE_H
#include <vector>


 
 
class OVEN_TABLE {
public:
    OVEN_TABLE();  
	void draw(float h , float w , float l ) ; 
	void drawOven(float h , float w , float l);
	void openCloseDoor(int state ) ; 


private : 
	float roateAngle ; 


};



#endif // MYCLASS_H