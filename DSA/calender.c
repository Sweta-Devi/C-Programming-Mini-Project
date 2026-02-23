/*WAP TO PRINT A CALENDER */
#include<stdio.h>
#include<stdlib.h>

int get_1st_dayofweek(int year)
{
	int day;
	day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
	return day;
}
int main()
{
	system("Color 8F");
	
	int year, month, day, dayinmonth, weekday = 0, startingday;
	
	printf("Enter your desired year : ");
	scanf("%d", &year);
	
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int monthday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)	//leap year
		monthday[1] = 29;
		
	startingday = get_1st_dayofweek(year);
	
	
	for(month = 0; month < 12; month++)
	{
		dayinmonth = monthday[month];
		printf("\n\n---------------%s-------------------\n", months[month]);
		printf("\n  Sun  Mon  Tue  Wed  Thru  Fri  Sat\n");
		
		for(weekday = 0; weekday < startingday; weekday++)
			printf("     ");
		
		for(day = 1; day <= dayinmonth; day++)
		{
			printf("%5d", day);
			
			if(++weekday > 6)
			{
				printf("\n");
				weekday = 0;
			}
			startingday = weekday;
		}
			
	}
	return 0;
}
