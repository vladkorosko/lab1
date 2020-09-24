#include "Connection.h"

void DateAndTime()
{
	Date work_date;
	const string types[13]
	{
		"Enter date;",
		"Autogenerate date;",
		"Show date(string);",
		"Show date(full information);",
		"Show number of week in month;",
		"Show number of week in year;",
		"Show statistics about current day of date;",
		"Show statistics about day(You can enter day);",
		"Change time zone(UTC);",
		"Get time difference between 2 dates;",
		"Increase date by time difference;",
		"Reduce date by time difference;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    You can do next operations:" << endl;
		for (int i = 0; i < 13; i++)
		{
			if (i == position)
				cout << red + "->  " << yellow + types[i] << endl;
			else cout << "    " << light_blue + types[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{
			if ((int)key == -32)
			{
				key = _getch();
				if ((int)key == 72)
				{
					if (position > 0)
						position--;
					else position = 12;
				}

				if ((int)key == 80)
				{
					if (position < 12)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			Date first_date;
			Date second_date;
			TimeDifference diff;
			int day = 0;
			int hour = 0;
			int minute = 0;
			int second = 0;
			string line = "";
			system("cls");
			switch (position)
			{
			case 0:
				try 
				{
					cout << blue + "Enter date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
					getline(cin, line);
					work_date = Date(line);
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 1:
				work_date.AutoGenerate();
				pause();
				break;
			case 2:
				cout << green << work_date.GetDate()<< endl;
				pause();
				break;
			case 3:
				cout << green << work_date << endl;
				pause();
				break;
			case 4:
				cout << green << "It is " << work_date.NumberOfWeekInMonth() << " in this month." << endl;
				pause();
				break;
			case 5:
				cout << green << "It is " << work_date.NumberOfWeekInYear() << " in this year." << endl;
				pause();
				break;
			case 6:
				try
				{
					vector<double> stats = work_date.Stats();
					cout << green << setw(12) << "Monday: " << setw(5) << setprecision(5) << stats[4] * 100 << '%' << endl;
					cout << green << setw(12) << "Tuesday: " << setw(5) << setprecision(5) << stats[5] * 100 << '%' << endl;
					cout << green << setw(12) << "Wednesday: " << setw(5) << setprecision(5) << stats[6] * 100 << '%' << endl;
					cout << green << setw(12) << "Thirsday: " << setw(5) << setprecision(5) << stats[0] * 100 << '%' << endl;
					cout << green << setw(12) << "Friday: " << setw(5) << setprecision(5) << stats[1] * 100 << '%' << endl;
					cout << green << setw(12) << "Saturday: " << setw(5) << setprecision(5) << stats[2] * 100 << '%' << endl;
					cout << green << setw(12) << "Sunday: " << setw(5) << setprecision(5) << stats[3] * 100 << '%' << endl;
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 7:
				try
				{
					cout << blue + "Enter day." << endl;
					cout << light_blue;
					getline(cin, line);
					day = EnterNumber(line);
					vector<double> stats = work_date.Stats(day);
					cout << green << setw(12) << "Monday: " << setw(5) << setprecision(5) << stats[4] * 100 << '%' << endl;
					cout << green << setw(12) << "Tuesday: " << setw(5) << setprecision(5) << stats[5]*100 << '%' << endl;
					cout << green << setw(12) << "Wednesday: " << setw(5) << setprecision(5) << stats[6]*100 << '%' << endl;
					cout << green << setw(12) << "Thirsday: " << setw(5) << setprecision(5) << stats[0]*100 << '%' << endl;
					cout << green << setw(12) << "Friday: " << setw(5) << setprecision(5) << stats[1]*100 << '%' << endl;
					cout << green << setw(12) << "Saturday: " << setw(5) << setprecision(5) << stats[2]*100 << '%' << endl;
					cout << green << setw(12) << "Sunday: " << setw(5) << setprecision(5) << stats[3]*100 << '%' << endl;
				}
				catch (logic_error& e)
				{
					cout << red << e.what()<< endl;
				}
				pause();
				break;
			case 8:
				try
				{
					cout << blue + "Enter new time zone(UTC)." << endl;
					cout << light_blue;
					getline(cin, line);
					int utc = EnterNumber(line);
					work_date.ChangeUTC(utc);
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 9:
				try
				{
					cout << blue + "Enter first date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
					getline(cin, line);
					first_date = Date(line);
					cout << blue + "Enter second date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
					getline(cin, line);
					second_date = Date(line);
					cout << green << first_date - second_date << endl;
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 10:
				try
				{
					cout << blue + "Enter first date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
					getline(cin, line);
					first_date = Date(line);
					cout << blue + "Enter number of days." << endl << light_blue;
					getline(cin, line);
					day = EnterNumber(line);
					cout << blue + "Enter number of hours." << endl << light_blue;
					getline(cin, line);
					hour = EnterNumber(line);
					cout << blue + "Enter number of minutes." << endl << light_blue;
					getline(cin, line);
					minute = EnterNumber(line);
					cout << blue + "Enter number of seconds." << endl << light_blue;
					getline(cin, line);
					second = EnterNumber(line);
					diff = TimeDifference(day, hour, minute, second);
					cout << green << first_date + diff << endl;
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 11:
				try
				{
					cout << blue + "Enter first date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
					getline(cin, line);
					first_date = Date(line);
					cout << blue + "Enter number of days." << endl << light_blue;
					getline(cin, line);
					day = EnterNumber(line);
					cout << blue + "Enter number of hours." << endl << light_blue;
					getline(cin, line);
					hour = EnterNumber(line);
					cout << blue + "Enter number of minutes." << endl << light_blue;
					getline(cin, line);
					minute = EnterNumber(line);
					cout << blue + "Enter number of seconds." << endl << light_blue;
					getline(cin, line);
					second = EnterNumber(line);
					diff = TimeDifference(day, hour, minute, second);
					cout << green << first_date - diff << endl;
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 12:
				end = true;
				break;
			default:
				break;
			}
		}
	}
}

void Sortlist()
{
	const string types[7]
	{
		"Integer;",
		"Double;",
		"Char;",
		"String;",
		"Vector<int>;",
		"Date and Time;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the class with which you want work:" << endl;
		for (int i = 0; i < 7; i++)
		{
			if (i == position)
				cout << red + "->  " << yellow + types[i] << endl;
			else cout << "    " << light_blue + types[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{
			if ((int)key == -32)
			{
				key = _getch();
				if ((int)key == 72)
				{
					if (position > 0)
						position--;
					else position = 6;
				}

				if ((int)key == 80)
				{
					if (position < 6)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			system("cls");
			switch (position)
			{
			case 0:
				SortListInt();
				break;
			case 1:
				SortListDouble();
				break;
			case 2:
				SortListChar();
				break;
			case 3:
				SortListString();
				break;
			case 4:
				SortListVectorInt();
				break;
			case 5:
				SortListDate();
				break;
			case 6:
				end = true;
				break;
			default:
				break;
			}
		}
	}
}

void InteractiveMode()
{
	const string types[3]
	{
		"Date and time;",
		"Sort list;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the class with which you want work:" << endl;
		for (int i = 0; i < 3; i++)
		{
			if (i == position)
				cout << red + "->  " << yellow + types[i] << endl;
			else cout << "    " << light_blue + types[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{
			if ((int)key == -32)
			{
				key = _getch();
				if ((int)key == 72)
				{
					if (position > 0)
						position--;
					else position = 2;
				}

				if ((int)key == 80)
				{
					if (position < 2)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			system("cls");
			switch (position)
			{
			case 0:
				DateAndTime();
				break;
			case 1:
				Sortlist();
				break;
			case 2:
				end = true;
				break;
			}
		}
	}
}
