#! Makefile
#
# author: wenlong.cao
# date :2016-11-08
# description:
# 	MULTI_THREADS := 1, the source code using multi-threads
#	CXXFLAGS := xxx   xxx is your source code used linked libs
# 	INCLUDE_DIRS   is headers files dirs

MULTI_THREADS ?= 0
CC := gcc


PROJECT := clickevent
SOURCES := $(wildcard *.c *.cpp)
OBJECT := $(patsubst %.c, %.o, $(SOURCES))
CXXFLAGS :=
INCLUDE_DIRS :=
LIBARIES :=

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	LINUX := 1
endif
ifeq ($(LINUX), 1)

	CC ?= /usr/bin/gcc
	GCCVERSION := $(shell $(CC) -dumpversion | cut -f1,2 -d.)
	INCLUDE_DIRS += /usr/local/include
	LIBARIES += /usr/local/lib #`pkg-config --cflags --libs protobuf`

	ifeq ($(MULTI_THREADS), 1)
		CXXFLAGS += -pthread

	endif
endif

# $(info $(SOURCES))
all: $(PROJECT)

zip:
	make all
	tar -zcvf clickevent.tar.gz ../clickevent/*

$(PROJECT): $(OBJECT)
	$(CC) $< -o $@

mouse.o: mouse.c
	$(CC) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf $(PROJECT)
	rm -rf *.tar.gz
