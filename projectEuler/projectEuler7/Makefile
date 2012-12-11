CFLAGS =-Wall -g -DNDEBUG

all: projectEuler7
	
checkPrime.o: checkPrime.h	
linkedList.o: linkedList.c linkedList.h
projectEuler7: projectEuler7.o linkedList.o checkPrime.o

clean:
	rm -f projectEuler7 checkPrime.o linkedList.o projectEuler7.o