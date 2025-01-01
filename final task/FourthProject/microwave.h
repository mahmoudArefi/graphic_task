#ifndef MICROWAVE_H
#define MICROWAVE_H
#include <vector>


 
 
class MICROWAVE {
public:
    MICROWAVE();  
	void draw(float h , float w , float l ) ; 
	void openCloseDoor(int s);
private : 
	float rotateAngle ; 
};



#endif // MYCLASS_H