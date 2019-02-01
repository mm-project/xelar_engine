#include "game/x_game.h"


int main( int argc, char* args[] )
{
XGame game;
	//TODO
    //game.parse_options(argc,argv);
    game.init();    
    game.start();    
	//game.stop();
	//TODO add try catch and handling
        
return 0;
}

#ifdef OS_WINDOWS
int WinMain( int argc, char* argv[] )
{
	//windows complains for undefinded symbol , this is stupid workaround
	main(argc,argv);
}
#endif
