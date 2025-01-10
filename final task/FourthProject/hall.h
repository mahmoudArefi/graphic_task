#ifndef HALL_H
#define HALL_H

 

class RestaurantHall {
public:
    RestaurantHall(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float hH , hW , hD ; 
	//sallon functions
	//void drawResturnSallon();
	void casherTable(float halfH,float halfW, float halfD) ;
	void drawChair  (float halfH,float halfW, float halfD) ;
};

#endif // ROOMWALLS_H