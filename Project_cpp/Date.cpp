#include "date.h"

Date::Date()
{
	day = month = year = 0;
}

void Date::zero()
{
	day = month = year = 0;
}

bool Date::setYear(int y)
{
	if (y < 0)
		return false;
	year = y;
	return true;
}

bool Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
		return true;
	}
	return false;
}

bool Date::setDay(int d)
{
	if (d >= 1 && d <= this->getDays())
	{
		day = d;
		return true;
	}
	return false;
}

Date::Date(int d, int m, int y)
{
	if(!setYear( y ) || !setMonth(m) || !setDay(d))
		zero();
}

bool Date::validDate(int d, int m , int y)
{
	if(y<0)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d > 1 || d > this->getDays())
		return false;
	return true;
}

void Date::setDate(int d, int m, int y)
{
	if (!validDate(d,m,y))
		zero();
	else
	{
		setYear(y);
		setMonth(m);
		setDay(d);
	}
}

Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

Date::~Date() {}

int Date::getDays()
{
	switch (month)
	{
	case 2:
		if (isLeapYear())
			return 29;
		return 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

bool Date::isLeapYear()
{
	if (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	return false;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d.day << "/" << d.month << "/" << d.year << endl;
	return out;
}