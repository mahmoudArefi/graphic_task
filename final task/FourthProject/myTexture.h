#ifndef MYTEXTURE_H
#define MYTEXTURE_H
#include <vector>


 
 
class MYTEXTURE {
public:
    MYTEXTURE();  
	std::vector<int> comedinaTexture;
    std::vector<int> staircaseTexture;
    std::vector<int> wardrobeTexture;
	std::vector<int> entryRoomTexture;
	std::vector<int> bathRoomTexture;
	std::vector<int> mainRoomTexture;
	std::vector<int> kitchenTexture;
	std::vector<int> fridgeTexture;

	int wardrobeDoor ; 
	int fridgeDoor ;
	int ovenDoor ;
	int microDoor ;
    void InitAllTexture();

private : 
	void initComedinaTexture();
	void initWardrobeTexture();
	void initEntryRoomTexture();
	void initBathRoomTexture();
	void initMainRoomTexture();
	void initKitchenTexture();
	void initFridgeTexture();
};



#endif // MYCLASS_H