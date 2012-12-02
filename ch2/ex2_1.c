#include <stdio.h>
#include <limits.h>
#include <float.h>

/* print ranges of different types */
int main()
{
	printf("The min of signed char: %d\n", SCHAR_MIN);
	printf("The max of signed char: %d\n", SCHAR_MAX);
	printf("The max of unsigned char: %u\n", UCHAR_MAX);
	printf("The min of signed short: %d\n", SHRT_MIN);
	printf("The max of signed short: %d\n", SHRT_MAX);
	printf("The max of unsigned short: %u\n", USHRT_MAX);
	printf("The min of signed int: %d\n", INT_MIN);
	printf("The max of signed int: %d\n", INT_MAX);
	printf("The max of unsigned int: %u\n", UINT_MAX);
	printf("The min of signed long: %ld\n", LONG_MIN);
	printf("The max of signed long: %ld\n", LONG_MAX);
	printf("The max of unsigned long: %lu\n", ULONG_MAX);
	
	/* the floating types */
	printf("The min of float: %e\n", FLT_MIN);
	printf("The max of float: %e\n", FLT_MAX);
	printf("The min of double: %e\n", DBL_MIN);
	printf("The max of double: %e\n", DBL_MAX);
	printf("The min of long double: %Le\n", LDBL_MIN);
	printf("The max of long double: %Le\n", LDBL_MAX);
	
	return 0;
}