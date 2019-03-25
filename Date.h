#include <iostream>
using namespace std;
#include <string>

class Date
{

	int day, month, year;

public:
	Date();
	Date(int m, int d, int y);
	//~Date();
	friend ostream & operator << (ostream &out, const Date &c); 
    friend istream & operator >> (istream &in,  Date &c);
	static string monthNames[13];
	bool operator == (Date &);
	Date & operator + (int c);
	Date & operator -- ();
	Date & operator -- (int a);
	int & operator [] (const int i);
	
};

static string monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};