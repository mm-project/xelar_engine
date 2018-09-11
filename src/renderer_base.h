#ifndef renderer_base_h
#define renderer_base_h

class LeRenderBase {
	public:
		virtual void draw() = 0;
		
	
};

class LeEventControllerBase {
	public:
		virtual void notify_mouse_pressed(unsigned int) = 0;
		virtual void notify_key_pressed(unsigned int) = 0;
		virtual void notify_mouse_move(unsigned int x, unsigned int y) = 0;
		virtual void enter_event_loop() = 0;
		virtual void update(unsigned int) = 0;
};


#endif