#include"SortList.h"
#include "NewFunctions.h"

ostream& operator<<(ostream& s, const Time& t)
{
	s << setfill('0') << setw(2) << t.GetHour() << ':' << setw(2) << t.GetMinute() << ':' << setw(2) << t.GetSecond();
	return s;
}

ostream& operator<<(ostream& s, const TimeDifference& diff)
{
	s << "Days: " << diff.GetDay() << "; Time: " << diff.GetTime();
	return s;
}

ostream& operator<<(ostream& s, const Date& date)
{
	s << date.GetNameOfDay() << ", the " << date.GetDay() << " of " + date.GetNameOfMonth() + ", " << date.GetYear() << endl << "UTC: ";
	if (date.GetUTC() >= 0)
		s << '+';
	s << setfill('0') << setw(2) << date.GetUTC() << "   Time: " << date.GetTime();
	return s;
}

ostream& operator<<(ostream& s, const vector<Date>& l)
{
	for (int i = 0; i < l.size(); i++)
		s << l[i].GetDate() << endl;
	return s;
}

ostream& operator<<(ostream& s, const vector<vector<int>>& v)
{
	for (const auto& i : v)
	{
		s << i << endl;
	}
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


bool operator==(const vector<int>& v1, const vector<int>& v2)
{
	bool result = true;
	if (v1.size() == v2.size())
		for (int i = 0; i < v1.size(); i++)
			result = result && (v1[i] == v2[i]);
	else return false;
	return result;
}

bool operator>(vector<int> v1, vector<int> v2)
{
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1.size() > v2.size())
		return true;
	if (v1.size() < v2.size())
		return false;
	bool result1 = true;
	if (v1.size() == v2.size())
		for (int i = 0; i < v1.size(); i++)
			result1 = result1 && v1[i] > v2[i];
	return result1;
}

bool operator<(vector<int> v1, vector<int> v2)
{
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1.size() < v2.size())
		return true;
	if (v1.size() > v2.size())
		return false;
	bool result1 = true;
	if (v1.size() == v2.size())
		for (int i = 0; i < v1.size(); i++)
			result1 = result1 && v1[i] < v2[i];
	return result1;
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

Date operator+(const Date& d1, const TimeDifference& diff)
{
	int second = d1.GetTime().GetSecond() + diff.GetTime().GetSecond();
	int minute = d1.GetTime().GetMinute() + diff.GetTime().GetMinute();
	int hour = d1.GetTime().GetHour() + diff.GetTime().GetHour();
	int days = d1.GetDateInDays() + diff.GetDay();
	if (second > 59)
	{
		second -= 60;
		minute++;
		if (minute > 59)
		{
			minute -= 60;
			hour++;
			if (hour > 23)
			{
				hour -= 24;
				days++;
			}
		}
	}
	return Date(d1.GetUTC(), days, hour, minute, second);
}

Date operator-(const Date& d1, const TimeDifference& diff)
{
	if (d1.GetDateInDays() > diff.GetDay() || (d1.GetDateInDays() == diff.GetDay() && d1.GetTime() > diff.GetTime()))
	{
		int second = d1.GetTime().GetSecond() - diff.GetTime().GetSecond();
		int minute = d1.GetTime().GetMinute() - diff.GetTime().GetMinute();
		int hour = d1.GetTime().GetHour() - diff.GetTime().GetHour();
		int days = d1.GetDateInDays() - diff.GetDay();
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
		return Date(d1.GetUTC(), days, hour, minute, second);
	}
	else throw logic_error("Result Date is lover then +0: 1970.1.1; 00:00:00");
}

void pause()
{
	cout << yellow << "Press any key to continue." << endl;
	cout << light_blue;
	_getch();
}

int EnterNumber(const string& number)
{
	istringstream date_stream(number);
	bool ok = true;
	int new_number;
	ok = ok && (date_stream >> new_number);
	ok = ok && date_stream.eof();

	if (!ok)
	{
		throw logic_error("Wrong number format: " + number);
	}
	return new_number;
}

double EnterDouble(const string& number)
{
	istringstream date_stream(number);
	bool ok = true;
	double new_number;
	ok = ok && (date_stream >> new_number);
	ok = ok && date_stream.eof();

	if (!ok)
	{
		throw logic_error("Wrong number format: " + number);
	}
	return new_number;
}

vector<int> AutoGenerateInt(int n)
{
	vector<int> result;
	for (int i = 0; i < n; i++)
		result.push_back(rand());
	return result;
}

vector<char> AutoGenerateChar(int n)
{
	vector<char> result;
	for (int i = 0; i < n; i++)
		result.push_back(41 + rand()%100);
	return result;
}

vector<double> AutoGenerateDouble(int n)
{
	vector<double> result;
	for (int i = 0; i < n; i++)
	{
		double r = rand();
		result.push_back(r / 1000);
	}
	return result;
}

vector<string> AutoGenerateString(int n)
{
	vector<string> result;
	for (int i = 0; i < n; i++)
	{
		string word = "";
		int sz = rand()%10+1;
		for (int i = 0; i < sz; i++)
			word += (char)((int)'a' + rand() % 25);
		result.push_back(word);
	}
	return result;
}

vector<vector<int>> AutoGenerateVectorInt(int n)
{
	vector<vector<int>> result;
	for (int i = 0; i < n; i++)
	{
		vector<int> list;
		int sz = rand() % 10 + 1;
		for (int i = 0; i < sz; i++)
			list.push_back(rand());
		result.push_back(list);
	}
	return result;
}

vector<Date> AutoGenerateDate(int n)
{
	vector<Date> result;
	for (int i = 0; i < n; i++)
	{
		Date d;
		d.AutoGenerate();
		result.push_back(d);
	}
	return result;
}