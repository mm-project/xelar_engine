#include "sound_manager.hpp"
#include "resource_manager.h"

LeSoundManager* LeSoundManager::get() {
    if ( !m_instance )
        m_instance = new LeSoundManager;
    return m_instance;
}

LeSoundManager::LeSoundManager() {
    init();
}

bool LeSoundManager::init() {
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
		return false; 
    
	wave = Mix_LoadWAV("./bin/cuckoo.wav");
	if (wave == NULL)
		return false;    
	
	// Load our music
	music = Mix_LoadMUS("./bin/track1.mp3");
	if (music == NULL)
		return false;

    return true;
    
	//while ( Mix_PlayingMusic() ) ;
}

void LeSoundManager::play(LeSoundName name) {
	if ( Mix_PlayChannel(-1, wave, 0) == -1 )
		return;
}

void LeSoundManager::play(LeMusicName name) {
	if ( Mix_PlayMusic( music, -1) == -1 )
		return ;
}

/*
LeSoundManager::~LeSoundManager() {

	// clean up our resources
	Mix_FreeChunk(wave);
	Mix_FreeMusic(music);
	
	// quit SDL_mixer
	Mix_CloseAudio();
    
}*/

LeSoundManager* LeSoundManager::m_instance = 0;
