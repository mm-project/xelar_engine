#include "resource_manager.h"
#include "image.h"

#include "../renderer/scene_controller.h"
#include <iostream>

LeResourceManager::LeResourceManager() {	
    m_rendering_manager = get_renderer();
}

LeImg LeResourceManager::get_img(int n) {
    //std::cout << "-->geting imgmnnum: " << n << std::endl;
    return m_ienum2obj[n];
    //return LeImg();
}

void LeResourceManager::register_image(int name, std::string filename) {
    //std::cout << "registering " << filename << " as number " << name << std::endl;
    m_ienum2obj[name]=LeImg(m_rendering_manager->register_image((m_img_path+filename).c_str()));
}

void LeResourceManager::set_mus_path(const std::string& p) {
    m_mus_path = p;
}

void LeResourceManager::set_img_path(const std::string& p) {
     m_img_path  = p;
}

void LeResourceManager::set_snd_path(const std::string& p) {
    m_snd_path = p;
}
