#pragma once
#include"Date.h"

template <typename T>
ostream& operator<<(ostream& s, vector<T> l);
ostream& operator<<(ostream& s, Time t);
ostream& operator<<(ostream& s, TimeDifference diff);
ostream& operator<<(ostream& s, Date date);
ostream& operator<<(ostream& s, vector<Date> l);
bool operator>(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator<(const Time& t1, const Time& t2);
bool operator>(Date d1, Date d2);
bool operator==(Date d1, Date d2);
bool operator<(Date d1, Date d2);
TimeDifference operator-(Date d1, Date d2);
Date operator+(const Date& d1, const TimeDifference& diff);
Date operator-(const Date& d1, const TimeDifference& diff);