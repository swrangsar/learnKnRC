#include <stdio.h>
#define LIMIT 1000

int main()
{
	int i, sum;
	i = 0;
	sum = 0;
	while (++i < LIMIT) {
		if ((i%3 == 0) || (i%5 == 0)) {
			sum += i;			
		}
	}
	
	printf("The sum is: %d\n", sum);
	return 0;
}