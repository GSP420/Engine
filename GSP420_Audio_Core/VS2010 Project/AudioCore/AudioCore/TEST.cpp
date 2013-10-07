// GSP 420 - Game Engine Design
// Audio Core - Audio Test
// by:
// Erick Garcia
// Zachary Gauld
// Christopher Cone
// Jordan Swanson
// Darion Wallace

#include "AudioCore.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void main ()
{
	//AudioCore - Object Declarations
	Sound *AudioCore = new Sound();  //instance sound class object
	ICore *ICore = new Sound(); //instance interface class object

	//AudioCore - Sound Effect Declarations
	SoundEffect *Jump_Sound; //sound effect variable names
	
	
	ICore->Startup(); //FMOD initiation
	
	
	//Background Music
	AudioCore->Load("Music.mp3");
	AudioCore->Play("Music.mp3");
	AudioCore->Play(false);

	//Sound Effects
	Jump_Sound = new SoundEffect ("Jump.wav");


	bool quit = false;

	cout << "TEST. Press Q to quit.\n" << endl;
	cout << "TEST. Press Spacebar to hear the jump sound.\n" <<endl;
	cout << "TEST. Press P to pause or un-pause the music.\n" <<endl;
	cout << "TEST. Press Z to decrease the volume of the music.\n" << endl;
	cout << "TEST. Press X to increase the volume of the music.\n" << endl;

	float Volume = 1.00f;

	while (!quit)
	{

		if (GetAsyncKeyState ('Q'))
		{
			quit = true;
		}
		if (GetAsyncKeyState (VK_SPACE))
		{
			Jump_Sound->Play();
		}
		if (GetAsyncKeyState ('P'))
		{
			AudioCore->TogglePause();
		}
		if (GetAsyncKeyState ('X'))
		{
			Volume += 0.10f;
			AudioCore->SetVolume(Volume);

		}
		if (GetAsyncKeyState ('Z'))
		{
			Volume -= 0.10f;
			AudioCore->SetVolume(Volume);

		}
	}
}