/* Danny Sullivan PA1 */
#include <stdio.h>
#include <math.h>

int year;
int daysInMonth;
int dayCode;
int FDOW;

int getYear() {
	printf(" Enter a year. ");
	scanf("%d", &year);

	printf("\n ***   CALENDAR for %d   ***\n", year);

	return year;
}

int isLeapYear(int year) {
	if(year % 4 == 0) {
		if(year % 100 == 0 && year % 400 != 0) {
			return 0;
		}
		return 1;
	}
	return 0;
}

int getFDOW(int year) {
	int baseYear = 2017;
	int FDOW = 0;

	/*finds the first day of the week based off of the year 2017, where the first
	day of the year was 0 (Sunday). If the year is a leap year, two days are 
	subtracted from the first day. If it is not, one day is subtracted. The year is
	incremented at the end of each loop through. */
	while(year < baseYear) {
		if(isLeapYear(baseYear-1)) {
			FDOW = FDOW - 2;
			if(FDOW < 0) {
				FDOW = FDOW + 7;
			}
		}
		else {
			FDOW = FDOW - 1;
			if(FDOW < 0) {
				FDOW = FDOW + 7;
			}
		}
		year++;
	}

	/*finds the first day of the week based off of the year 2017, where the first
	day of the year was 0 (Sunday). If the year is a leap year, two days are 
	added from the first day. If it is not, one day is added. The year is
	decremented at the end of each loop through. */
	while(year > baseYear) {
		if(isLeapYear(baseYear)) {
			FDOW = FDOW + 2;
			if(FDOW > 6) {
				FDOW = FDOW - 7;
			}
		}
		else {
			FDOW = FDOW + 1;
			if(FDOW > 6) {
				FDOW = FDOW - 7;
			}
		}
		year--;
	}
	dayCode=FDOW;
	return FDOW;
}

void printMonthName(int year, int month) {
	if(month == 0)printf("\n%s", " January ");
	
	if(month == 1) printf("\n\n%s", " February ");
	
	if(month == 2) printf("\n\n%s", " March ");
	
	if(month == 3) printf("\n\n%s", " April ");
	
	if(month == 4) printf("\n\n%s", " May ");
	
	if(month == 5) printf("\n\n%s", " June ");
	
	if(month == 6) printf("\n\n%s", " July ");
	
	if(month == 7) printf("\n\n%s", " August ");
	
	if(month == 8) printf("\n\n%s", " September ");
	
	if(month == 9) printf("\n\n%s", " October ");
	
	if(month == 10) printf("\n\n%s", " November ");
	
	if(month == 11) printf("\n\n%s", " December ");
	
	printf("%d\n", year);
	printf("\n Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	
}

int getdaysinmonth(int month,int year){
	if(month==0)return 31;

	if(month==1 && isLeapYear(year))return 29;
	if(month==1 && !isLeapYear(year))return 28;
	
	if(month==2)return 31;

	if(month==3)return 30;
	
	if(month==4)return 31;
	
	if(month==5)return 30;
	
	if(month==6)return 31;
	
	if(month==7)return 31;
	
	if(month==8)return 30;
	
	if(month==9)return 31;
	
	if(month==10)return 30;
	
	if(month==11)return 31;
}

void printMonth(int year, int month, int startingDay) {

	daysInMonth = getdaysinmonth(month,year);

	/*prints out spacing for first day/week of the month*/
	for(int day = 1; day <= 1 + dayCode * 5; day++) {
		printf(" ");
	}
	
	/*prints out spacing for the rest of the days. If the days end up
	being greater than 7 (one full week), it prints a new line for a new week */
	for(int day = 1; day <= daysInMonth; day++) {
		printf("%3d", day);
		if((day + dayCode) % 7 > 0) {
			printf("  ");
		}
		else {
			printf("\n ");
		}
	}

	dayCode = ((dayCode + daysInMonth) % 7);
}

void printCalendar(int year, int startingDay) {
	/*runs through every month and prints its name and days out*/
	for(int month = 0; month < 12; month++) {
		printMonthName(year, month);
		printMonth(year, month, startingDay);
	}
}

int main() {
	int year = getYear();
	int startingDay = getFDOW(year);
	printCalendar(year, startingDay);
	return 0;
}