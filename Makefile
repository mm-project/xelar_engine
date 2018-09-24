PROGNAME:=SimpleGame
SRCS:=$(wildcard src/*.cpp)
INCS:=

ifeq ($(OS),Windows_NT)
	OUT=$(PROGNAME).exe
	FLAGS=-Wfatal-errors -g -DTEXT_RENDER -DIMAGE_RENDER -DOS_WINDOWS -static-libgcc -static-libstdc++ 
	#LIBS=-L ./deps/win/SDL2/lib/win32 -lSDL2 -L ./deps/win/SDL2_image-2.0.3/x86/lib -lSDL2_image 
	LIBS=./deps/win/SDL2-2.0.8/lib/x86/SDL2.lib  ./deps/win/SDL2_image-2.0.3/lib/x86/SDL2_image.lib  ./deps/win/SDL2_ttf-2.0.14/lib/x86/SDL2_ttf.lib
	INCLS=$(INCS) -I ./deps/win/SDL2-2.0.8/include -I ./deps/win/SDL2_image-2.0.3/include -I ./deps/win/SDL2_ttf-2.0.14/include
else
	OUT=$(PROGNAME).bin
	#LIBS=./deps/linux/SDL2/libSDL2.a ./deps/linux/SDL2_ttf/libSDL2_ttf.a -lfreetype -ldl -lrt
	#INCLS=-I ./deps/linux/SDL2/include -I ./deps/linux/SDL2_ttf
	FLAGS=-Wfatal-errors -g -DIMAGE_RENDER -DOS_LINUX 
	#FLAGS=-DTEXT_RENDER
	LIBS=-L ./deps/linux/SDL2_image-2.0.3 -lSDL2_image ./deps/linux/SDL2/libSDL2.a  -ldl -lrt -pthread 
	INCLS=$(INCS)-I ./deps/linux/SDL2/include -I ./deps/linux/SDL2_image-2.0.3/include 
endif



ifeq ($(USER),levons)
	FLAGS=-Wfatal-errors -g -DIMAGE_RENDER -DOS_LINUX 
	LIBS=-L ~/levi/downloads/SDL2-2.0.5/build/.libs -lSDL2 -lfreetype -ldl -lrt
	INCLS=-I ~/levi/downloads/SDL2-2.0.5/include 
endif

default:
	clear
	rm -f ./bin/$(OUT) 
	g++ -std=c++11 $(SRCS) $(FLAGS) $(INCLS) $(LIBS) -o ./bin/$(OUT)
	cp ./deps/win/SDL2-2.0.8/lib/x86/SDL2.dll ./bin
	cp ./deps/win/SDL2_ttf-2.0.14/lib/x86/* ./bin
	cp ./deps/win/SDL2_image-2.0.3/lib/x86/* ./bin
	
