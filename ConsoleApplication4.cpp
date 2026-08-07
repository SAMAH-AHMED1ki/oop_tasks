
#include <vector>
using namespace std;
#include <iostream>
// we can use date orr time without define unused variables from the other 
struct date {
	int year;
	int month;
	int day;
	
};
struct tim {
	int hour;
	int minute;
	int second;
	
};

// if i need use them together 
// we can use without rewritr all them agian
struct datetime {
	date d1;
	tim t1;

};
int main()
{

}
