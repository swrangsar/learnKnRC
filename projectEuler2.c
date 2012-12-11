#include <stdio.h>
#define LIMIT 4000000

int main()
{
	int a, b, fibonacci, sum;
	a = 0;
	b = 1;
	
	sum = 0;
	
	while ((fibonacci = a + b) <= LIMIT) {
		if (fibonacci%2 == 0)
			sum += fibonacci;
		a = b;
		b = fibonacci;
	}
	
	printf("The sum is: %d\n", sum);
	return 0;
}