#ifndef MYTEXTURE_H
#define MYTEXTURE_H
#include <vector>


 
 
class MYTEXTURE {
public:
    MYTEXTURE();  
	std::vector<int> comedinaTexture;
    std::vector<int> staircaseTexture;
    std::vector<int> wardrobeTexture;
	int wardrobeDoor ; 
    void InitAllTexture();

private : 
	void initComedinaTexture();
	void initWardrobeTexture();

   
};



#endif // MYCLASS_H