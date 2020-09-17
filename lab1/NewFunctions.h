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

ostream& operator<<(ostream& s, Date date)
{
	s << date.GetNameOfDay() << ", the " << date.GetDay() << " of " + date.GetNameOfMonth() + ", " << date.GetYear() << endl << "UTC: ";
	if (date.GetUTC() >= 0)
		s << '+';
	s << setfill('0') << setw(2) << date.GetUTC() << "   Time: " << date.GetTime();
	return s;
}

bool operator>(Time t1, Time t2)
{
	if (t1.GetHour() > t2.GetHour())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() > t2.GetMinute())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() == t2.GetMinute() && t1.GetSecond() > t2.GetSecond())
		return true;
	return false;
}

bool operator==(Time t1, Time t2)
{
	return t1.GetTime() == t2.GetTime();
}

bool operator<(Time t1, Time t2)
{
	if (t1.GetHour() < t2.GetHour())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() < t2.GetMinute())
		return true;
	else if (t1.GetHour() == t2.GetHour() && t1.GetMinute() == t2.GetMinute() && t1.GetSecond() < t2.GetSecond())
		return true;
	return false;
}
