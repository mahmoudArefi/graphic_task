#ifndef ROOMWALLS_H
#define ROOMWALLS_H

class RoomWalls {
public:
    RoomWalls();                                 // Constructor
    void drawRoomWalls(float height, float width, float length); // Method to define RoomWalls
	void drawHouse();

private : 
	enum RoomType {kitchen , bathroom, mainRoom , entryRoom};
	void drawEntryRoom(); 
    float roomHeight  , roomWidth  , roomDepth ;
};

#endif // ROOMWALLS_H
