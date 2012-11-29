#include <stdio.h>

/* print Celsius-Fahrenheit table
for fahr = 0, 20, ..., 300 */
	
int main()
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	celsius = lower;
	
	printf("Celsius\tFahrenheit\n\n");
	
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * (celsius + 32.0);
		printf("%7.0f\t%10.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}