PROGNAME=SimpleGame
#FLAGS=-DTEXT_RENDER
SRCS=src/main.cpp src/menu.cpp

ifeq ($(USER),levons)
	LIBS=-L ~/levi/downloads/SDL2-2.0.5/build/.libs -lSDL2 -lfreetype -ldl -lrt
	INCLS=-I ~/levi/downloads/SDL2-2.0.5/include 
else
	#LIBS=./deps/linux/SDL2/libSDL2.a ./deps/linux/SDL2_ttf/libSDL2_ttf.a -lfreetype -ldl -lrt
	#INCLS=-I ./deps/linux/SDL2/include -I ./deps/linux/SDL2_ttf
	LIBS=./deps/linux/SDL2/libSDL2.a -ldl -lrt -pthread 
	INCLS=-I ./deps/linux/SDL2/include 
endif

OUT=$(PROGNAME).bin
ifeq ($(OS),Windows_NT)
	OUT=$(PROGNAME).exe
	FLAGS=-DIMAGE_RENDER -DOS_WINDOWS -static-libgcc -static-libstdc++ 
	#LIBS=-L ./deps/win/SDL2/lib/win32 -lSDL2 -L ./deps/win/SDL2_image-2.0.3/x86/lib -lSDL2_image 
	LIBS=./deps/win/SDL2-2.0.8/lib/x86/SDL2.lib  ./deps/win/SDL2_image-2.0.3/lib/x86/SDL2_image.lib
	INCLS=-I ./deps/win/SDL2-2.0.8/include -I ./deps/win/SDL2_image-2.0.3/include
endif



default:
	#cd ./src
	clear
	rm -f ./bin/$(OUT) 
	g++ -Wfatal-errors -g $(SRCS) $(FLAGS) $(INCLS) $(LIBS) -o ./bin/$(OUT)
	cp ./deps/win/SDL2-2.0.8/lib/x86/SDL2.dll ./bin
	cp ./deps/win/SDL2_image-2.0.3/lib/x86/* ./bin
