#include <stdio.h>
#define LIMIT 100

long sumOfSquares(long limit);
long squareOfSum(long limit);

int main()
{
	long difference;
	difference = squareOfSum(LIMIT) - sumOfSquares(LIMIT);
	printf("The difference is: %ld\n", difference);
	
	return 0;
}

long sumOfSquares(long limit)
{
	long i, sum;
	i = sum = 0;
	while (++i <= limit)
		sum += (i * i);
	return sum;
}

long squareOfSum(long limit)
{
	long sum;
	sum = (limit * (limit+1))/2;
	return (sum * sum);
}