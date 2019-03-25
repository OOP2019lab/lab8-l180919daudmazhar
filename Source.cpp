#include "Date.h"
using namespace std;
#include <iostream>
#include <string>


Date::Date()
{
	day = 1, month = 1; year = 2000;
	
}

Date::Date(int m, int d, int y)
{
	if ((d >0 && d <= 30) && (m > 0 && m <= 12) && (y>999 && y < 10000))
		day = d, month = m, year = y;
	else day = 1, month = 1, year = 2000;
	
}

 ostream & operator << (ostream &out,  const Date &c)
{
	out << monthNames[c.month] << " " << c.day << ", " << c.year << endl;
	return out;
}

 istream & operator >> (istream &in, Date &c)
 {
	 cout << "Enter new month \n";
	 in >> c.month;
	 cout << "Enter new day \n";
	 in >> c.day;
	 cout << "Enter new year \n";
	 in >> c.year;
	 return in;
 }

 bool Date::operator==(Date &d)
 {
	 if (d.year == this->year && d.day == this->day && d.month == this->month)
		 return true;
	 else
		 return false;
 }

Date & Date:: operator + (int c)
	{
		this->day = this->day + c;

		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month++;
			if(this->month > 12 )
			{
				this->year++;
				this->month = this->month - 12;
			}
		}
		return *this;
	}

Date & Date:: operator--()
{
	--this->day;
	if (this->day <= 0)
	{
		this->day = 30+this->day;
		this->month--;
		if(this->month <= 0)
		{
			this->month = 12 + this->month;
			this->year--;
		}
	}
	return*this;
}

Date & Date:: operator--(int a)
{
	this->day--;
	if (this->day <= 0)
	{
		this->day = 30+this->day;
		this->month--;
		if(this->month <= 0)
		{
			this->month = 12 + this->month;
			this->year--;
		}
	}
	return *this;
}

int & Date:: operator [](const int i)
{
	if (i == 0)
		return this->day;
	else if (i==1)
		return this->month;
	else if (i==2)
		return this->year;
	else if (i < 0 && i>2)
		{
			int x = 0;
			cout << "Index can only be 0, 1 or 2 \n ";
			return x;
	}
}