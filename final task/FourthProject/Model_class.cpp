#include "ModelClass.h" 


//ModelVar::ModelVar(Model_3DS* modelParam, double scaleParam, double height, double width, double length)
//    : model(modelParam), scale(scaleParam), h(height), w(width), l(length) {
//		modelParam->scale = scaleParam ;
//}

double ModelVar::getHalfHeight(){
	return (h*scale)*0.25; 
	//return 1  ; 
}

double ModelVar::getHalfD(){
		return (w * scale ) * 0.5 ; 
}

double ModelVar::getHalfW(){
	return (w * scale ) * 0.5 ; 
}

