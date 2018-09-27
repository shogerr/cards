CC=g++
CXXFLAGS=-g -std=c++14 -Wall -pedantic

ODIR=obj

CARD_SRC=card.cpp test_card.cpp
CARD_OBJ=$(CARD_SRC:%.cpp=%.o)

RENDERER_SRC=renderer.cpp test_renderer.cpp glutils.cpp
RENDERER_OBJ=$(RENDERER_SRC:%.cpp=%.o)

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:%.cpp=%.o)

MKDIR_P=mkdir -p


all: debug directories test_renderer test_card

debug:
	@echo $(RENDERER_OBJ:%=obj/%)

directories:
	$(MKDIR_P) $(ODIR)

test_card: $(CARD_OBJ:%=obj/%)
	$(CC) -o $@ $^ $(CXXFLAGS)

test_renderer: $(RENDERER_OBJ:%=obj/%)
	$(CC) -o $@ $^ $(CXXFLAGS) $(shell sdl2-config --libs) -lGL -lGLEW

$(CARD_OBJ:%=obj/%): obj/%.o: src/%.cpp
	$(CC) -c -o $@ $^ $(CXXFLAGS)

$(RENDERER_OBJ:%=obj/%): obj/%.o: src/%.cpp
	$(CC) -c -o $@ $^ $(CXXFLAGS) $(shell sdl2-config --cflags) -I/usr/include/GL

clean:
	rm -rf ./obj/
	rm -f test_deck
	rm -f test_card
	rm -f test_renderer
	

