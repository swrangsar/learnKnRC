#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month && month < 13; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}


int main()
{
	printf("February 29th of 2012 is day %d of that year.\n", day_of_year(2012, 2, 29));
	printf("March 1st of 2013 is day %d of that year.\n", day_of_year(2013, 3, 1));
	
	int pmonth, pday;
	month_day(2012, 60, &pmonth, &pday);
	printf("60th day of 2012 is : %d %d\n", pmonth, pday);
	month_day(2013, 60, &pmonth, &pday);
	printf("60th day of 2013 is : %d %d\n", pmonth, pday);

	return 0;
}