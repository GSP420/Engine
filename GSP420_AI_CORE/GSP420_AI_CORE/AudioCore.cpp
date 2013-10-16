// GSP 420 - Game Engine Design
// Audio Core - Main
// by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// Darion Wallace

#include "AudioCore.h"
#include <iostream>

using namespace std;

void FMODErrorCheck (FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        cout << "FMOD error! (" << result << ") " << FMOD_ErrorString (result) << endl;
        exit (-1);
    }
}

bool Sound :: s_enabled = true; //Is the sound enabled?
char *Sound :: s_current_sound; //current sound to play

//FMOD system declarations
FMOD_RESULT Sound :: s_result;
FMOD_SYSTEM *Sound :: s_fmod_system;
FMOD_SOUND *Sound :: s_sound;
FMOD_CHANNEL *Sound :: s_channel;
FMOD_RESULT result;

void Sound :: Startup ()
{
	s_result = FMOD_System_Create (&s_fmod_system);
	assert (s_result == FMOD_OK);
	//initialize the system with 8 channels
	s_result = FMOD_System_Init (s_fmod_system, 8, FMOD_INIT_NORMAL, 0);
	assert (s_result == FMOD_OK);
	FMOD_Channel_SetVolume (s_channel, 0.0f);

	FMODErrorCheck (result);
}

void Sound :: Update ()
{
	FMOD_System_Update (s_fmod_system);

	FMODErrorCheck (result);
}

void Sound :: SetVolume (float vol) 
{
	if (s_enabled && vol >= 0.0f && vol <= 1.0f) 
	{
		FMOD_Channel_SetVolume (s_channel, vol);
    }

	FMODErrorCheck (result);
}

//load sound file
void Sound :: Load (const char * filename) 
{
	s_current_sound = (char *) filename;

    if (s_enabled) 
	{
		s_result = FMOD_Sound_Release (s_sound);
        s_result = FMOD_System_CreateStream (s_fmod_system, s_current_sound, FMOD_SOFTWARE, 0, &s_sound);
		assert (s_result == FMOD_OK);
	}

	FMODErrorCheck (result);
}

void Sound :: Unload (void) 
{
	s_result = FMOD_Sound_Release (s_sound);
	assert (s_result == FMOD_OK);

	FMODErrorCheck (result);
}

void Sound :: Play (bool pause = false) //no augment is needed to play by default
{
	if (true == s_enabled) 
	{
		s_result = FMOD_System_PlaySound (s_fmod_system, s_sound, NULL, pause, &s_channel);
		assert (s_result == FMOD_OK);
        FMOD_Channel_SetMode (s_channel, FMOD_LOOP_NORMAL);
    }

	FMODErrorCheck (result);
}

bool Sound :: GetSoundState () 
{
    return s_enabled;

	FMODErrorCheck (result);
}

//gets the name of the current sound
char* Sound :: GetCurrentSound ()
{
	return s_current_sound;

	FMODErrorCheck (result);
}

//pause or unpause the sound
void Sound :: SetPause (bool pause) 
{
	FMOD_Channel_SetPaused (s_channel, pause);

	FMODErrorCheck (result);
}

//turn sound on or off
void Sound :: SetSound (bool s) 
{
    s_enabled = s;

	FMODErrorCheck (result);
}

//toggles sound on and off
void Sound :: ToggleSound (void) 
{
	s_enabled = !s_enabled;
    if (s_enabled == true) 
	{
		Load (s_current_sound); 
		Play (s_enabled); 
	}

    if (s_enabled == false) 
	{
		Unload ();
	}

	FMODErrorCheck (result);
}

//toggle pause on and off
void Sound :: TogglePause (void) 
{
	FMOD_BOOL p;
    FMOD_Channel_GetPaused (s_channel, &p);
    FMOD_Channel_SetPaused (s_channel, !p);

	FMODErrorCheck (result);
}


void Sound :: Shutdown()
{
	FMOD_System_Release (s_fmod_system);
}


//===========================================================================
//Sound Effects
//===========================================================================
SoundEffect :: SoundEffect (char* filename)
{
	b_enabled = true;
	m_sound_name = filename;
	m_result = FMOD_System_CreateSound (Sound::GetSystem(), m_sound_name, FMOD_SOFTWARE, 0, &m_sound);
	assert(m_result == FMOD_OK);

	FMODErrorCheck (result);
}

void SoundEffect :: Play ()
{
	m_result = FMOD_System_PlaySound (Sound :: GetSystem (), m_sound, NULL, false, 0);
	assert(m_result == FMOD_OK);

	FMODErrorCheck (result);
}

//Gets the sound system
FMOD_SYSTEM* Sound :: GetSystem ()
{
 return s_fmod_system;

 FMODErrorCheck (result);
}