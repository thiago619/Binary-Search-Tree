OBJ=obj
SRC=src
BIN=bin
LIB=lib
CC=gcc
CXX=g++
CXXFLAGS=-fPIC -O3 -c -W -Wall -ansi -pedantic -g



all: lib/libbinarysearchtree.a test

test: obj/test.o obj/binarysearchtree.o
	$(CXX) -o bin/test.exe obj/binarysearchtree.o obj/test.o

obj/test.o: src/test.cpp
	$(CXX) -o obj/test.o src/test.cpp -Iinclude -c -W -Wall -ansi -pedantic

obj/binarysearchtree.o: include/binarysearchtree.hpp src/binarysearchtree.cpp
	$(CXX) -o obj/binarysearchtree.o src/binarysearchtree.cpp -Iinclude $(CXXFLAGS)

lib/libbinarysearchtree.a: obj/binarysearchtree.o
	ar cr lib/libbinarysearchtree.a obj/binarysearchtree.o


