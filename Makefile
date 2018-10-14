CC = gcc
CFLAGS= -g -Wall 

INCLUDES=-I/usr/local/lib \
-I/usr/local/include/SDL2 

# Include all the c files from the current project
SOURCES=$(wildcard src/*.c) 

# Default location for the libSDL2 on a mac
LIBRARIES=/usr/local/lib/libSDL2.a

# Dependencies of libSDL2
EXTRA_LDFLAGS =  -lm -liconv  -Wl,-framework,CoreAudio -Wl,-framework,AudioToolbox -Wl,-framework,ForceFeedback -lobjc -Wl,-framework,CoreVideo -Wl,-framework,Cocoa -Wl,-framework,Carbon -Wl,-framework,IOKit -Wl,-weak_framework,QuartzCore -Wl,-weak_framework,Metal

TARGET=bin/app

all: build
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) $(LIBRARIES) $(EXTRA_LDFLAGS) -o $(TARGET)

build:
	@mkdir -p bin