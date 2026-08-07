
#include <vector>
using namespace std;
#include <iostream>
struct date {
	int year;
	int month;
	int day;
	void year_month_day(int year, int month) {
		cout << year << "." << month << "." << day << endl;
	}
	void year_month(int year, int month) {
		cout << year << "." << month << endl;
	}
	void month_day(int month, int day) {
		cout << month << "." << day << endl;
	}
};
struct tim {
	int hour;
	int minute;
	int second;
	// more clear easy to read and print 
	void hour_minute_second(int hour, int minute, int second) {
		cout << hour << ":" << minute << ":" << second << endl;
	}
	// save memore but ambiguos hour or minute 
	void calcsec(int total) {
		
		cout << total;
	}
};

int main()
{
	date d1;
	tim j;
	d1.year_month(2006, 8);
	j.hour_minute_second(12, 0, 0);

}
