#include	<iostream>
using namespace std;

class Date{
private:
	int year;
	int month;
	int day;

public:
	void add_day(int);
	void add_month(int);
	void add_year(int);
	void show_date();


	//defualt constructor
	Date(){
		year = 2019;
		month = 11;
		day = 8;
	}

	//constructor
	Date(int _year, int _month, int _day){
		year = _year;
		month = _month;
		day = _day;
	}
};

void Date::add_day(int inc){
	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
	int i = month;

	if(month_day[i-1] - day >= inc){
		day += inc;
		return;
	}
	else{
		add_month(1);
		day = 1;

		inc = inc - (month_day[i-1] - day) - 1;
		i++;
	}

	while(true){
		if((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
			month_day[1] = 29;
		else
			month_day[1] = 28;

		if(inc - month_day[i-1] >= 0){
			add_month(1);
			inc = inc - month_day[i-1] ;
		}
		else if(inc - month_day[i-1] < 0){
			day += inc;
			break;
		}

		i++;
		if(i > 12)
			i -= 12;
	}
}

void Date::add_month(int inc){
	add_year((inc + month - 1) / 12);
	month = month + inc % 12;
	month = (month == 12 ? 12 : month % 12);
}

void Date::add_year(int inc){
	year += inc;
}

void Date::show_date(){
	cout << "Date : " << year << " / " << month << " / " << day << endl;
}

int main(){
	Date day;
	
	day.set_date(2011, 3, 1);
	day.show_date();

	return 0;
}
