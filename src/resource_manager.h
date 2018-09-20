#ifndef resource_manager_h
#define resource_manager_h

class LeImages = {IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3 }
//class LeSounds = {IMG_PLAYER,  IMG_COIN,  IMG_ENEMY1, IMG_ENEMY2, IMG_ENEMY3 }


class LeResourceManager
{
	public:
		LeResourceManager() {
			register_images();
			
		}
		
		void register_images() {
			register_image(path+"debilik.png");
		}
		
		LeImg get_image() {
		
		}

	public:
		//register_image();
		//get_image();

	private:
		std::map<LeImg,LeImg> m_enum2img;
		std::string path;
};

#endif