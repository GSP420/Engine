// GSP 420 - Game Engine Design
// Audio Core - Header
// by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// Darion Wallace

#include "fmod.h"
#include "assert.h"
#include "fmod_errors.h"
#include "Main_Core/ICore.h"
using namespace std;

class Sound : public ICore
{
private:
	static bool s_enabled;						//is the sound enabled?
	static char *s_current_sound;				//current sound to play

	//FMOD system declarations
	static FMOD_RESULT s_result;
	static FMOD_SYSTEM *s_fmod_system;
	static FMOD_SOUND *s_sound;
	static FMOD_CHANNEL *s_channel;


public:

	void Startup ();
	void Update ();
	void Shutdown ();

	//FMOD system declarations
	static FMOD_SYSTEM* GetSystem ();

	//Sound control
	static void SetVolume (float vol);			//sets the volume of the playing sound
	static void Load (const char *filename);	
	static void Unload ();
	static void Play (bool pause);

	//Getters
	static bool GetSoundState ();				//checks whether the sound is on
	static char* GetCurrentSound ();

	//Setters
	static void SetPause (bool pause);			//pause or unpause the sound
	static void SetSound (bool sound);			//set the sound on or off

	//Toggles
	static void ToggleSound ();
	static void TogglePause ();

};

class SoundEffect								
{
private:
	bool b_enabled;
	char* m_sound_name;

	//FMOD system declarations
	FMOD_SOUND* m_sound;
	FMOD_RESULT m_result;

public:
	SoundEffect (char* filename);
	void Play ();
};