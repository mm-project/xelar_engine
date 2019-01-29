#include "maze_generation/game.h"


int main( int argc, char* args[] )
{
LeGame game;
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
