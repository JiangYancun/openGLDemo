ifeq ($(OS),Windows_NT)
LDFLAGS=-lopengl32 -lglu32 -lglut32
EXECUTABLE=main.exe
BINDIR=bin/NT/
else
LDFLAGS=-Wall -lglfw -lm -lGL -lGLU -lGLEW
EXECUTABLE=main
BINDIR=bin/Linux/
endif

CFLAGS=-g -DDEBUG

all:
	g++ src/main.cpp -c -o $(BINDIR)main.o $(CFLAGS) 
	g++ $(BINDIR)main.o $(LDFLAGS) -o $(BINDIR)$(EXECUTABLE) 

clean:
	rm $(BINDIR)main.o $(BINDIR)$(EXECUTABLE)
