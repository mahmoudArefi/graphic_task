#ifndef MYMODEL_H
#define MYMODEL_H
#include "Model_3DS.h"
#include "modelClass.h"


class MYMODEL {
public:
    MYMODEL();                 // Constructor
    void initAllMyModel();     // Method to initialize all models

    // Models
    Model_3DS* tank;
    ModelVar* table;
	ModelVar* bed;
	ModelVar* woodTable;

    Model_3DS* tree;

private:
    void initTank();
    void initTable();
    void initTree();
	void initBed();
	void initWoodTable();
};

#endif // MYMODEL_H
