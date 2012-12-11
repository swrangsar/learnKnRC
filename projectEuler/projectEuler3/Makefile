CFLAGS =-Wall -g -DNDEBUG

all: projectEuler3
	
checkPrime.o: checkPrime.h	
linkedList.o: linkedList.c linkedList.h
projectEuler3: projectEuler3.o linkedList.o checkPrime.o

clean:
	rm -f projectEuler3 checkPrime.o linkedList.o projectEuler3.o