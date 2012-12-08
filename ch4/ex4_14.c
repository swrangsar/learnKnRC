#include <stdio.h>

#define swap(t, x, y)	{\
t temp;\
temp = y;\
y = x;\
x = temp;\
}

int main()
{
	int x, y;
	x = 'X';
	y = 'Y';
	printf("x: %c y: %c\n", x, y);
	swap(char, x, y);
	printf("x: %c y: %c\n", x, y);
	
	return 0;
}