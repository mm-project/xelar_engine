#ifndef resource_manager_h
#define resource_manager_h

#include "service.h"
#include "image.h"


#include "../renderer/scene_controller.h"
//#include "enumarations"

#include <map>
#include <string>



class LeResourceManager: public LeService<LeResourceManager>
{
	public:
		friend class LeService<LeResourceManager>;

private:
        LeResourceManager();

		LeResourceManager(const LeResourceManager&);
		LeResourceManager& operator=(LeResourceManager&);
       
	public:
        LeImg get_img(int n);
        
    public:
        void register_image(int, std::string filename);
        
        void set_mus_path(const std::string& p);
        void set_img_path(const std::string& p);
        void set_snd_path(const std::string& p);
        

    private:
        //void register_images();
        //id register_sounds();
        //id register_music();

    private:
        std::map<int,LeImg> m_ienum2obj;
        std::string m_img_path;
        std::string m_snd_path;
        std::string m_mus_path;
        //std::string m_common_path;
        
        LeRenderingControllerImplBase* m_rendering_manager;
        
};

#endif
