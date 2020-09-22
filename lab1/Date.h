#pragma once
#include"SortList.h"

class Time
{
private:
	int hour;
	int minute;
	int second;

	bool CheckHour(const int& new_hour) const
	{
		return new_hour >= 0 && new_hour < 24;
	}

	bool CheckMinute(const int& new_minute) const
	{
		return new_minute >= 0 && new_minute < 60;
	}

public:
	Time()
	{
		hour = 0;
		minute = 0;
		second = 0;
	};

	void SetTime(const int& new_hour, const int& new_minute, const int& new_second)
	{
		if (CheckHour(new_hour) && CheckMinute(new_minute) && CheckMinute(new_second))
		{
			hour = new_hour;
			minute = new_minute;
			second = new_second;
		}
		else
		{
			if (!CheckHour(new_hour))
				throw logic_error("Hour value is invalid: " + to_string(new_hour));
			if (!CheckMinute(new_minute))
				throw logic_error("Minute value is invalid: " + to_string(new_minute));
			if (!CheckMinute(new_second))
				throw logic_error("Second value is invalid: " + to_string(new_second));
		}
	}

	Time(const int& new_hour, const int& new_minute, const int& new_second)
	{
		SetTime(new_hour, new_minute, new_second);
	}

	int GetHour() const
	{
		return hour;
	}

	int GetMinute()const
	{
		return minute;
	}

	int GetSecond()const
	{
		return second;
	}

	string GetTime() const
	{
		string result = "";
		string line = "00";
		line += to_string(hour);
		while (line.size() > 2)
			line.erase(line.begin());
		result += line;
		result += ':';
		line = "00";
		line += to_string(minute);
		while (line.size() > 2)
			line.erase(line.begin());
		result += line;
		result += ':';
		line = "00";
		line += to_string(second);
		while (line.size() > 2)
			line.erase(line.begin());
		result += line;
		return result;
	}
};

class Date
{
private:
	int year;
	int month;
	int day;
	Time mytime;
	string day_name;
	string month_name;
	int UTC;
	int all_days;

	const vector<int> daysInMonth = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };

	bool LeapYear(const int& new_year) const
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

	bool CheckYear(const int& year)const
	{
		return year > 1969;
	}

	bool CheckMonth(const int& new_month) const
	{
		return new_month < 13 && new_month > 0;
	}

	bool CheckDay(const int& new_day, const int& new_month, const int& new_year) const
	{
		return new_day <= daysInMonth[new_month - 1] + LeapYear(new_year) * (new_month == 2) && new_day > 0;
	}

	bool CheckUTC(const int& utc) const
	{
		return utc > -13 && utc < 13;
	}

	int CountDaysInYear()const
	{
		int days = 0;
		for (int i = 0; i < month - 1; i++)
		{
			if (i == 1 && LeapYear(year))
				days++;
			days += daysInMonth[i];
		}
		days += day;
		days--;
		return days;
	}

	int CountAllDays(const int& new_year, const int& new_month, const int& new_day)const
	{
		int all_days = 0;
		for (int i = 1970; i < new_year; i++)
			if (LeapYear(i))
				all_days += 366;
			else all_days += 365;
		for (int i = 0; i < new_month - 1; i++)
		{
			if (i == 1 && LeapYear(new_year))
				all_days++;
			all_days += daysInMonth[i];
		}
		all_days += new_day;
		all_days--;
		return all_days;
	}

	vector<int> ConvertToDate(int days)
	{
		days++;
		int new_year = 1970;
		for (new_year; days > 365 + LeapYear(new_year); new_year++)
			if (LeapYear(new_year))
				days -= 366;
			else days -= 365;
		int new_month = 1;
		for (new_month; days > daysInMonth[new_month - 1]; new_month++)
		{
			if (new_month == 2 && LeapYear(new_year))
				days--;
			days -= daysInMonth[new_month-1];
		}
		vector<int> a(3, 0);
		a[0] = new_year;
		a[1] = new_month;
		a[2] = days;
		return a;
	}

	string NameOfDay() const
	{
		switch (all_days % 7)
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

	string NameOfMonth(const int& new_month) const
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

	void Set(const int& utc, const int& new_year, const int& new_month, const int& new_day,
			const int& new_hour, const int& new_minute, const int& new_second)
	{
		if (CheckYear(new_year) && CheckMonth(new_month) && CheckDay(new_day, new_month, new_year) && CheckUTC(utc))
		{
			year = new_year;
			month = new_month;
			day = new_day;
			UTC = utc;
			mytime = Time(new_hour, new_minute, new_second);
			month_name = NameOfMonth(new_month);
			all_days = CountAllDays(new_year, new_month, new_day);
			day_name = NameOfDay();
		}
		else
		{
			if (!CheckYear(new_year))
				throw logic_error("Year value is invalid: " + to_string(new_year));
			if (!CheckMonth(new_month))
				throw logic_error("Month value is invalid: " + to_string(new_month));
			if (!CheckDay(new_day, new_month, new_year))
				throw logic_error("Day value is invalid: " + to_string(new_day));
			if (!CheckUTC(utc))
				throw logic_error("UTC value is invalid: " + to_string(utc));
		}
	}
public:
	Date() 
	{
		year = 1970;
		month = 1;
		day = 1;
		UTC = 0;
		mytime = Time();
	};

	Date(const int& utc, const int& days, const int& new_hour, const int& new_minute, const int& new_second)
	{
		vector<int> a = ConvertToDate(days);
		int new_year = a[0], new_month = a[1], new_day = a[2];
		Set(utc, new_year, new_month, new_day, new_hour, new_minute, new_second);
	}

	Date(const int& utc, const int& new_year, const int& new_month, const int& new_day,
		const int& new_hour, const int& new_minute, const int& new_second)
	{
		Set(utc, new_year, new_month, new_day, new_hour, new_minute, new_second);
	}

	Date (const string& date)
	{
		istringstream date_stream(date);
		bool ok = true;

		int utc;
		ok = ok && (date_stream >> utc);
		ok = ok && (date_stream.peek() == ':');
		date_stream.ignore(1);
		ok = ok && (date_stream.peek() == ' ');
		date_stream.ignore(1);

		int new_year;
		ok = ok && (date_stream >> new_year);
		ok = ok && (date_stream.peek() == '.');
		date_stream.ignore(1);

		int new_month;
		ok = ok && (date_stream >> new_month);
		ok = ok && (date_stream.peek() == '.');
		date_stream.ignore(1);

		int new_day;
		ok = ok && (date_stream >> new_day);
		ok = ok && (date_stream.peek() == ';');
		date_stream.ignore(1);
		ok = ok && (date_stream.peek() == ' ');
		date_stream.ignore(1);

		int new_hour;
		ok = ok && (date_stream >> new_hour);
		ok = ok && (date_stream.peek() == ':');
		date_stream.ignore(1);

		int new_minute;
		ok = ok && (date_stream >> new_minute);
		ok = ok && (date_stream.peek() == ':');
		date_stream.ignore(1);

		int new_second;
		ok = ok && (date_stream >> new_second);
		ok = ok && date_stream.eof();

		if (!ok) 
		{
			throw logic_error("Wrong date format: " + date);
		}

		Set(utc, new_year, new_month, new_day, new_hour, new_minute, new_second );
	}
	
	void operator=(const Date& d)
	{
		Set(d.GetUTC(), d.GetYear(), d.GetMonth(), d.GetDay(), d.GetTime().GetHour(), d.GetTime().GetMinute(), d.GetTime().GetSecond());
	}

	void AutoGenerate()
	{
		int utc = -12 + rand() % 25;
		int new_year = 1970 + rand() % 1000;
		int new_month = 1 + rand() % 12;
		int new_day = 1 + rand() % (daysInMonth[new_month-1] + (month == 2) * LeapYear(new_year));
		int new_hour = rand() % 24;
		int new_minute = rand() % 60;
		int new_second = rand() % 60;
		Set(utc, new_year, new_month, new_day, new_hour, new_minute, new_second);
	}

	int GetUTC() const
	{
		return UTC;
	}

	int ChangeUTC(int utc)
	{
		if (CheckUTC(utc))
		{
			int difference = utc - UTC;
			int new_hour = mytime.GetHour() + difference;
			if (new_hour > 23)
			{
				new_hour -= 24;
				day++;
				if (!CheckDay(day, month, year))
				{
					day = 1;
					month++;
					if (!CheckMonth(month))
					{
						month = 1;
						year++;
					}
				}
			}
			else if (new_hour < 0)
			{
				new_hour += 24;
				day--;
				if (!CheckDay(day, month, year))
				{
					month--;
					if (!CheckMonth(month))
					{
						year--;
						if (!CheckYear(year))
							throw logic_error("Result is lover then UTC +0: 1970.1.1 00:00:00.");
						else month = 12;
					}
					day = daysInMonth[month - 1] + (month == 2) * LeapYear(year);
				}
			}
			all_days = CountAllDays(year, month, day);
			day_name = NameOfDay();
			month_name = NameOfMonth(month);
			UTC = utc;
			mytime.SetTime(new_hour, mytime.GetMinute(), mytime.GetSecond());
		}
	}

	Time GetTime()const
	{
		return mytime;
	}

	int GetDay() const
	{
		return day;
	}

	string GetNameOfDay() const
	{
		return day_name;
	}

	int GetMonth() const
	{
		return month;
	}

	string GetNameOfMonth() const
	{
		return month_name;
	}

	int GetYear() const
	{
		return year;
	}

	int GetDateInDays() const
	{
		return all_days;
	}

	string GetDate()const
	{
		string result = "";
		if (UTC >= 0)
			result += '+';
		result += to_string(UTC);
		result += ": ";
		result += to_string(year);
		result += '.';
		string line = "00";
		line += to_string(month);
		while (line.size() > 2)
			line.erase(line.begin());
		result += line;
		result += '.';
		line = "00";
		line += to_string(day);
		while (line.size() > 2)
			line.erase(line.begin());
		result += line;
		result += "; ";
		result += mytime.GetTime();
		return result;
	}

	int NumberOfWeekInYear()
	{
		int days = CountDaysInYear();
		Date BeginOfYear(UTC, year, 1, 1, 0, 0, 0);
		int week = 0;
		if ((BeginOfYear.all_days % 7 + 4) % 7)
		{
			week++;
			days -= 7;
			days += (BeginOfYear.all_days % 7 + 4) % 7;
		}
		if (days > 0)
			return days / 7 + week + 1;
		else return 1;
	}

	vector<double> Stats()
	{
		int k = 0;
		vector<double> stat(7, 0);
		for (int i = 1970; i < year; i++)
			for (int j = 1; j < 13; j++)
				if (CheckDay(day, j, i))
				{
					stat[CountAllDays(i, j, day) % 7]++;
					k++;
				}
		for (int i = 1; i < month; i++)
			if (CheckDay(day, i, year))
			{
				stat[CountAllDays(year, i, day) % 7]++;
				k++;
			}
		stat[CountAllDays(year, month, day) % 7]++;
		k++;
		for (int i = 0; i < stat.size(); i++)
		{
			stat[i] /=k;
		}
		return stat;
	}

	vector<double> Stats(int stat_day)
	{
		if (stat_day < 32 && stat_day)
		{
			vector<double> stat(7, 0);
			int k = 0;
			for (int i = 1970; i < year; i++)
				for (int j = 1; j < 13; j++)
					if (CheckDay(stat_day, j, i))
					{
						stat[CountAllDays(i, j, stat_day) % 7]++;
						k++;
					}
			for (int i = 1; i < month; i++)
				if (CheckDay(stat_day, i, year))
				{
					stat[CountAllDays(year, i, stat_day) % 7]++;
					k++;
				}
			if (CheckDay(stat_day, month, year))
			{
				stat[CountAllDays(year, month, stat_day) % 7]++;
				k++;
			}
			for (int i = 0; i < stat.size(); i++)
			{
				stat[i] /= k;
			}
			return stat;
		}
		else throw logic_error("Day value is invalid: " + to_string(stat_day));
	}
};

class TimeDifference
{
	int day;
	Time t;
public:
	TimeDifference()
	{
		day = 0;
		t = Time();
	}

	TimeDifference(const int& new_day, const int& new_hour, const int& new_minute, const int& new_second)
	{
		day = new_day;
		t = Time(new_hour, new_minute, new_second);
	}

	int GetDay() const
	{
		return day;
	}

	Time GetTime() const
	{
		return t;
	}
};