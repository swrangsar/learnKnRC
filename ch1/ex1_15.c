#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
	
float celsiusOf(float fahr);
	
int main()
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	
	printf("Fahrenheit\tCelsius\n\n");
	
	while (fahr <= upper) {
		celsius = celsiusOf(fahr);
		printf("%10.0f\t%7.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float celsiusOf(float fahr)
{
	float celsius;
	celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}