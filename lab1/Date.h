#pragma once
#include"SortList.h"

class Date
{
private:
	time_t local_time;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	string day_name;
	string month_name;
	int UTC;

	const vector<int> daysInMonth = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };

	bool LeapYear(int new_year) const
	{

		bool leapyear = false;
		if (!(new_year % 4))
		{
			leapyear = true;
			if (!(new_year % 100))
			{
				leapyear = false;
				if (!(new_year % 400))
					leapyear = true;
			}
		}
		return leapyear;
	}

	bool CheckMonth(int new_month) const
	{
		return new_month < 13 && new_month > 0;
	}

	bool CheckDay(int new_day, int new_month, int new_year) const
	{
		return new_day < daysInMonth[new_month - 1] + LeapYear(new_year) * (new_month == 2) && new_day > 0;
	}

	string NameOfDay(int new_day)
	{
		switch (new_day % 7)
		{
		case 0:
			return "Thurday";
		case 1:
			return "Friday";
		case 2:
			return "Saturday";
		case 3:
			return "Sunday";
		case 4:
			return "Monday";
		case 5:
			return "Tuesday";
		default:
			return "Wednesday";
		}


	}

	string NameOfMonth(int new_month)
	{
		switch (new_month)
		{
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "Augest";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		default:
			return "December";
		}
	}
public:
	Date() {};

	Date(time_t Time, int utc)
	{
		UTC = utc;
		Time += utc * 3600;
		second = Time % 60;
		Time /= 60;
		minute = Time % 60;
		Time /= 60;
		hour = Time % 24;
		Time /= 24;
		day = Time;
		day++;
		day_name = NameOfDay(day);
		year = 1970;
		while (day > -1)
		{
			if (LeapYear(year))
				day -= 366;
			else
				day -= 365;
			year++;
		}
		year--;
		if (LeapYear(year))
			day += 366;
		else
			day += 365;
		month = 1;
		while (!CheckDay(day, month, year))
		{
			month++;
			day -= daysInMonth[month - 1] + LeapYear(year) * (month == 2);
		}
		month_name = NameOfMonth(month);
	}

	Date(string date)
	{
		
	}


};