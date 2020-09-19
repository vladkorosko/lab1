#pragma once
#include"Date.h"

template <typename T>

ostream& operator<<(ostream& s, vector<T> l)
{
	s << " ";
	for (int i = 0; i < l.size(); i++)
		s << l[i] << " ";
	s << endl;
	return s;
}

ostream& operator<<(ostream& s, Time t)
{
	s << setfill('0') << setw(2) << t.GetHour() << ':' << setw(2) << t.GetMinute() << ':' << setw(2) << t.GetSecond();
	return s;
}

ostream& operator<<(ostream& s, TimeDifference diff)
{
	s << diff.GetDay() << "; " << diff.GetTime();
	return s;
}

ostream& operator<<(ostream& s, Date date)
{
	s << date.GetNameOfDay() << ", the " << date.GetDay() << " of " + date.GetNameOfMonth() + ", " << date.GetYear() << endl << "UTC: ";
	if (date.GetUTC() >= 0)
		s << '+';
	s << setfill('0') << setw(2) << date.GetUTC() << "   Time: " << date.GetTime();
	return s;
}

bool operator>(const Time& t1, const Time& t2)
{
	if (t1.GetHour() > t2.GetHour())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() > t2.GetMinute())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() == t2.GetMinute() && t1.GetSecond() > t2.GetSecond())
		return true;
	return false;
}

bool operator==(const Time& t1, const Time& t2)
{
	return t1.GetTime() == t2.GetTime();
}

bool operator<(const Time& t1, const Time& t2)
{
	if (t1.GetHour() < t2.GetHour())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() < t2.GetMinute())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() == t2.GetMinute() && t1.GetSecond() < t2.GetSecond())
		return true;
	return false;
}

bool operator>(Date d1, Date d2)
{
	if (d1.GetUTC() > d2.GetUTC())
		d2.ChangeUTC(d1.GetUTC());
	else d1.ChangeUTC(d2.GetUTC());
	if (d1.GetYear() > d2.GetYear())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() > d2.GetMonth())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() > d2.GetDay())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() == d2.GetDay() && d1.GetTime() > d2.GetTime())
		return true;
	return false;
}

bool operator==(Date d1, Date d2)
{
	if (d1.GetUTC() > d2.GetUTC())
		d2.ChangeUTC(d1.GetUTC());
	else d1.ChangeUTC(d2.GetUTC());
	return d1.GetDate() == d2.GetDate();
}

bool operator<(Date d1, Date d2)
{
	if (d1.GetUTC() > d2.GetUTC())
		d2.ChangeUTC(d1.GetUTC());
	else d1.ChangeUTC(d2.GetUTC());
	if (d1.GetYear() < d2.GetYear())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() < d2.GetMonth())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() < d2.GetDay())
		return true;
	else if (d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() == d2.GetDay() && d1.GetTime() < d2.GetTime())
		return true;
	return false;
}

TimeDifference operator-(Date d1, Date d2)
{
	if (d1 > d2)
	{
		int utc = max(d1.GetUTC(), d2.GetUTC());
		d1.ChangeUTC(utc);
		d2.ChangeUTC(utc);
		int second = d1.GetTime().GetSecond() - d2.GetTime().GetSecond();
		int minute = d1.GetTime().GetMinute() - d2.GetTime().GetMinute();
		int hour = d1.GetTime().GetHour() - d2.GetTime().GetHour();
		int days = d1.GetDateInDays() - d2.GetDateInDays();
		if (second < 0)
		{
			second += 60;
			minute--;
			if (minute < 0)
			{
				minute += 60;
				hour--;
				if (hour < 0)
				{
					hour += 24;
					days--;
				}
			}
		}
		return TimeDifference(days, hour, minute, second);
	}
	else throw logic_error("Fisrt date is lover then second date.");
}