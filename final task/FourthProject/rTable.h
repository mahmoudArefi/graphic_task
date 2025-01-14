#ifndef RTABLE_H
#define RTABLE_H

 

class RTable {
public:
	RTable();
    RTable(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float tH , tW , tD ; 
	//sallon functions
	void drawChairTable();
};

#endif // ROOMWALLS_H