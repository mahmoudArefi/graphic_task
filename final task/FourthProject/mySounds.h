#ifndef SOUNDS_H
#define SOUNDS_H
//#include "Wave.h" 
#include "sound.h"

extern HWND		hWnd;
class SoundVar {
public : 
	 DirectSoundBuffer Sound;
     DirectSoundManager SoundManager;
	 SoundVar (){}
     SoundVar(char* filePath ) {
        // Initialize the sound manager with the window handle
        SoundManager.Initialize(hWnd);
        
        // Create the sound using the provided file path
        SoundManager.CreateSound(filePath, Sound);
    }
};


class MySounds {
public:
    MySounds();  
	void initAllSounds();

	 SoundVar testSound ; 
	 SoundVar sound1 ; 

};



#endif // MYCLASS_H