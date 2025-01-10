#ifndef PHARMACY_H
#define PHARMACY_H

#include "parallelRectangle.h"


class Pharmacy {
public:
    Pharmacy(float height, float width, float depth);                              
	void draw();

private : 
    //public variables 
	float pH , pW , pD ; 
	ParallelRectangle prObj ;

	void drawStoreHouse();
	void drawWallBetweenWareHouseAndPharmacy();
	void drawPharmacyMeanPart();
};

#endif // ROOMWALLS_H