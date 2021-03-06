#pragma once
#include"Date.h"
#include<conio.h>

const string colour = "\u001B[37m";
const string light_blue = "\u001B[36m";
const string violet = "\u001B[35m";
const string blue = "\u001B[34m";
const string green = "\u001B[32m";
const string yellow = "\u001B[33m";
const string red = "\u001B[31m";

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& l)
{
	for (int i = 0; i < l.size() - 1; i++)
		s << l[i] << " ";
	s << l[l.size() - 1];
	return s;
}
ostream& operator<<(ostream& s, const Time& t);
ostream& operator<<(ostream& s, const TimeDifference& diff);
ostream& operator<<(ostream& s, const Date& date);
ostream& operator<<(ostream& s, const vector<Date>& l);
ostream& operator<<(ostream& s, const vector<vector<int>>& v);

bool operator>(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator<(const Time& t1, const Time& t2);
bool operator>(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator<(const Date& d1, const Date& d2);

TimeDifference operator-(Date d1, Date d2);
Date operator+(const Date& d1, const TimeDifference& diff);
Date operator-(const Date& d1, const TimeDifference& diff);

void pause();

int EnterNumber(const string& number);
double EnterDouble(const string& number);

vector<int> AutoGenerateInt(int n);
vector<char> AutoGenerateChar(int n);
vector<double> AutoGenerateDouble(int n);
vector<string> AutoGenerateString(int n);
vector<vector<int>> AutoGenerateVectorInt(int n);
vector<Date> AutoGenerateDate(int n);