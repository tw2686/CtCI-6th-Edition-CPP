CC = g++

CFLAGS = -g -Wall
LDFLAGS = -g

executables = vector-test
objects = vector-test.o

.PHONY: default
default: $(executables)

$(objects): vector.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
