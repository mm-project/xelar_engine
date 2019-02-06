#ifndef scene_controller_h
#define scene_controller_h

#include "rendering_controller_impl_base.h"
#include "../skeleton/common.h"

#include <iostream>

class LeSceneController 
{

    public:
        static void set_rendering_controller(LeSceneController* controller);
        static LeSceneController* get_current_controller();
		static LeRenderingControllerImplBase* get_renderer();
	
    public:
		LeSceneController();
        virtual void notify_mouse_pressed(unsigned int) = 0;
        virtual void notify_mouse_move(unsigned int x, unsigned int y) = 0;
        virtual void notify_key_pressed(unsigned int k) = 0;
        virtual void draw() = 0;
		virtual void init() = 0;
		virtual void update(unsigned int) = 0;	

    
    public:
		static LeSceneController* m_renderer_controller;
        static LeRenderingControllerImplBase* m_impl;


};


namespace {
    LeRenderingControllerImplBase* get_renderer() {
        //std::cout << "get rendeerer" << LeRenderingControllerImplBase::get() << std::endl;
        //assert(LeRenderingControllerImplBase::get());
        return 	LeSceneController::get_renderer();
    }

    LeSceneController* get_controller() {
        return LeSceneController::get_current_controller();
    }
    
}


#endif
