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

	int glass ;
	//resturant texture 
	std::vector<int> resturantChairTexture ;
	std::vector<int> restuarntTableTexture ;
	int restuarntWall , restuarntFloor , restuarntRooF ;
	std::vector<int> artBoard ;
	//resturant kithen
	std::vector<int> majlaTexture ;
	std::vector<int> kithenInterface ; 
	std::vector<int> kithenInterfaceDoor ; 
	int wardrobeDoor ; 
    void InitAllTexture();

	//elevator
	int elevatorDoor ; 

	// yamen object
	std::vector<int> fridgeTexture;
	int fridgeDoor ;
	int ovenDoor ;
	int microDoor ;

private : 
	void initComedinaTexture();
	void initWardrobeTexture();
	void initEntryRoomTexture();
	void initBathRoomTexture();
	void initMainRoomTexture();
	void initKitchenTexture();

	//resturant function
	void initResturantTexture();


	void initFridgeTexture();
};



#endif // MYCLASS_H