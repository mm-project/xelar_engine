#ifndef resource_manager_h
#define resource_manager_h

#include "image.h"

#include <map>
#include <string>

/*
enum LeImageType = {IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3 };
enum LeSoundType = {SND_COIN,  SND_SWIM,  SND_DAMAGE, SND_FUCK, SND_WIN };
enum LeMusicType = {MUS_GAME,  MUS_MENU,  MUS_PAUSE };
*/

class LeResourceManager
{
	public:
		LeResourceManager();

	public:
		void register_images();
		//LeImg get_image();

	private:
		//std::map<LeImageType,LeImg> m_enum2img;
		std::string path;
};

#endif