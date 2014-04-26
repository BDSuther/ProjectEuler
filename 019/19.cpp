#include <iostream>

using namespace std;

/*
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

int isLeap(int year){
	if(year % 100 == 0){
		if (year % 400 == 0){
			return 1;
		}
		return 0;
	} else if (year % 4 == 0){
		return 1;
	}
	return 0;
}

int main(){
	int days = 366;
	int sundays = 0;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int leap;
	//go for 99 years
	for(int i = 1; i <= 100; i++){
		//12 months in a year
		for(int j = 0; j < 12; j++){
			leap = isLeap(i);
			if (days % 7 == 0){
				sundays++;
			}
			days += month[j];
			if (j == 1){
				days += 1*leap;
			}
		}
	}

	cout << "The number of sundays that fell on the first of the month in the twentieth century is " << sundays << endl;

}
