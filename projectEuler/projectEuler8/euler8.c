#include <stdio.h>
#define MAXSIZE 1000

void populateIntArray(int array[]);

int main()
{
	int input[MAXSIZE], max, i, temp;
	populateIntArray(input);
	i = max = 0;
	
	while ((i+4) < MAXSIZE) {
		if ((temp = (input[i]*input[i+1]*input[i+2]*input[i+3]*input[i+4])) > max)
			max = temp;
		++i;
	}
	
	printf("The largest product is: %d\n", max);
	return 0;
}

void populateIntArray(int array[])
{
	int c, i;
	i = 0;
	while ((c = getchar()) && i < MAXSIZE) {
		if (c >= '0' && c <= '9') {
			array[i++] = c-'0';
		}
	}
	if (i == MAXSIZE)
		printf("Input array successfully populated :)\n");
	return;
}