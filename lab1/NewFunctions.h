#pragma once
#include"Date.h"
#include<conio.h>

const string light_blue = "\u001B[36m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

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
void pause();