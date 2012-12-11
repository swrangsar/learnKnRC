CFLAGS = -Wall -g -DNDEBUG

all: projectEuler5

linkedList.o: linkedList.h
projectEuler5.o: projectEuler5.c
projectEuler5: linkedList.o projectEuler5.o

clean:
	rm -f projectEuler5 projectEuler5.o linkedList.o