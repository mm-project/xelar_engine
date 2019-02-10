#include "../skeleton/common.h"
#include "scene_controller.h"

#include "sdl_renderer.h"


LeSceneController* LeSceneController::m_renderer_controller = 0;
LeRenderingControllerImplBase* LeSceneController::m_impl = new LeSdlRenderer;

void LeSceneController::set_rendering_controller(LeSceneController* controller){
	LOG("set_rendering_controller %p \n",(void*)controller);       
	m_renderer_controller = controller;
}

LeSceneController* LeSceneController::get_current_controller() {
    return m_renderer_controller; 
}

LeRenderingControllerImplBase* LeSceneController::get_renderer() {
    return m_impl;
    //return LeSdlRenderer::get();
}

//const char* title) { //fixme no title 
LeSceneController::LeSceneController() { 
    //wtf 
    //m_controllers.push_back(this);
}


