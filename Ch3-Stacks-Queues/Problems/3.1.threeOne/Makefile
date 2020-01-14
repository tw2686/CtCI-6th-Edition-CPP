CC = g++

CFLAGS = -g -Wall -std=c++11
LDFLAGS = -g

executables = test
objects = test.o

.PHONY: default
default: $(executables)

$(objects): FixedMultiStack.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
