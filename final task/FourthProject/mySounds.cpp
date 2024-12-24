#include "mySounds.h" 
#include "Wave.h"
#include "sound.h"



MySounds::MySounds() {
    // Constructor implementation
}

extern HWND		hWnd ;
void MySounds::initAllSounds(){

	 testSound = SoundVar("rifle.wav");
	 sound1 = SoundVar("tank-engine.wav");
}