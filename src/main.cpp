#include "skeleton/game.h"
//#include "maze_generation/window.hpp"
#include "Qt_maze_game/game.hpp"

int main( int argc, char* args[] )
{
LeGame game;
    //game.register_entry_point(new window);
    game.register_entry_point(new GameWindow);
	//TODO
    //game.parse_options(argc,argv);
	game.start();    
	//game.stop();
return 0;
}

#ifdef OS_WINDOWS
int WinMain( int argc, char* argv[] )
{
	//windows complains for undefinded symbol , this is stupid workaround
	main(argc,argv);
}
#endif
