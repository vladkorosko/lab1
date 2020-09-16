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

