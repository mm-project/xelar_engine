PROGNAME:=SimpleGame
SKELETON_SRCS:=$(wildcard src/skeleton/*.cpp)
RENDERER_SRCS:=$(wildcard src/renderer/*.cpp)
PHYSICS_SRCS:=$(wildcard src/physics/*.cpp)
GAME_SRCS:=$(wildcard src/maze_generation/*.cpp)
SRCS:=src/main.cpp $(SKELETON_SRCS) $(RENDERER_SRCS) $(GAME_SRCS) $(PHYSICS_SRCS)

INCS:=
FLAGS:=-Wno-narrowing

ifeq ($(OS),Windows_NT)
	OUT=$(PROGNAME).exe
	FLAGS+=-Wfatal-errors -g -DTEXT_RENDER -DIMAGE_RENDER -DOS_WINDOWS -static-libgcc -static-libstdc++ 
	#LIBS=-L ./deps/win/SDL2/lib/win32 -lSDL2 -L ./deps/win/SDL2_image-2.0.3/x86/lib -lSDL2_image 
	LIBS+=./deps/win/SDL2-2.0.8/lib/x86/SDL2.lib  ./deps/win/SDL2_image-2.0.3/lib/x86/SDL2_image.lib  ./deps/win/SDL2_ttf-2.0.14/lib/x86/SDL2_ttf.lib
	INCLS+=$(INCS) -I ./deps/win/SDL2-2.0.8/include -I ./deps/win/SDL2_image-2.0.3/include -I ./deps/win/SDL2_ttf-2.0.14/include
else
	OUT=$(PROGNAME).bin
	#INCLS=-I ./deps/linux/SDL2/include -I ./deps/linux/SDL2_ttf
	FLAGS+=-Wfatal-errors -g -DIMAGE_RENDER -DOS_LINUX 
	LIBS+=-lBox2D -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lSDL2  -ldl -lrt -pthread -lfreetype -lpng16
	#LIBS+=-lBox2D -lasound -L ./deps/ci -lpng16 -lsndio -lwayland-egl -lwebp -lfreetype -ldl -lrt -pthread ./deps/linux64/SDL2/libSDL2.a ./deps/linux64/SDL2_image/libSDL2_image.a -L ./deps/ci -lpng16 -lsndio -lwayland-egl -lwebp -lfreetype -ldl -lrt -pthread -lasound
	#LIBS+=-lBox2D  -L ./deps/linux64/SDL2 -lSDL2 -L ./deps/ci -lpng16 -lsndio -lwayland-egl -lwebp -L ./deps/linux64/SDL2_image -lSDL2_image -lfreetype -ldl -lrt  -pthread 
	INCLS+=$(INCS) -I ./deps/linux/SDL2/include -I ./deps/linux/SDL2_image-2.0.3/include 
endif



default:
	clear
	rm -f ./bin/$(OUT)  
	g++ -std=c++11 $(SRCS) $(FLAGS) $(INCLS) $(LIBS) -o ./bin/$(OUT)
	cp ./deps/win/SDL2-2.0.8/lib/x86/SDL2.dll ./bin
	cp ./deps/win/SDL2_ttf-2.0.14/lib/x86/* ./bin
	cp ./deps/win/SDL2_image-2.0.3/lib/x86/* ./bin
	
