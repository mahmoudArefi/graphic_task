#ifndef MODELCLASS_H
#define MODELCLASS_H
#include "Model_3DS.h"

class ModelVar {
public:
    Model_3DS* model;  // Pointer to Model_3DS
    float scale;
    double h, w, l;

    // Constructor
    ModelVar(Model_3DS* modelParam, double scaleParam, double height, double width, double length)
        : model(modelParam), scale(scaleParam), h(height), w(width), l(length) {
		model->scale = scale ;
	}
	double getHalfHeight();
	double getHalfW() ; 
	double getHalfD() ; 
};



#endif // MYMODEL_H
