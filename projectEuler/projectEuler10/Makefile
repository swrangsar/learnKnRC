CFLAGS =-Wall -g -DNDEBUG

all: euler10
	
checkPrime.o: checkPrime.h	
linkedList.o: linkedList.c linkedList.h
euler10: euler10.o linkedList.o checkPrime.o

clean:
	rm -f euler10 checkPrime.o linkedList.o euler10.o