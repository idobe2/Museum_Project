#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
private :
	int day;
	int month;
	int year;
	bool setDay(int );
	bool setMonth(int );
	bool setYear(int );
public:
		Date();
		Date(int ,int ,int );
		Date(const Date&);
		~Date();
		void zero();
		int getDay(){return day;}
		int getMonth(){return month;}
		int getYear(){return year;}
		bool validDate(int, int, int);
		void setDate(int, int, int);
		int getDays();
		bool isLeapYear();
		friend ostream& operator << (ostream& out, const Date& d);
};
#endif
