#include "Connection.h"

void DateAndTime()
{
	Date work_date;
	Date first_date;
	Date second_date;
	TimeDifference diff;
	const string types[12]
	{
		"Enter date;",
		"Show date(string);",
		"Show date(full information);",
		"Show number of week in month;",
		"Show number of week in year;",
		"Show statistics about current day of date;"
		"Show statistics about day(You can enter day);"
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
		for (int i = 0; i < 12; i++)
		{
			if (i == position)
				cout << red + "->  " << light_blue + types[i] << endl;
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
					else position = 11;
				}

				if ((int)key == 80)
				{
					if (position < 11)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			string line = "";
			system("cls");
			switch (position)
			{
			case 0:
				cout << blue + "Enter date(Format: 'utc: yyyy.mm.dd; hh:mm:ss' (utc between [-12,+12]))" << endl << light_blue;
				getline(cin,line);
				try 
				{
					work_date = Date(line);
				}
				catch (logic_error& e)
				{
					cout << red << e.what() << endl;
				}
				pause();
				break;
			case 1:
				cout << green << work_date.GetDate()<< endl;
				pause();
				break;
			case 2:
				cout << green << work_date << endl;
				pause();
				break;
			case 3:
				cout << green << "It is " << work_date.NumberOfWeekInMonth() << " in this month." << endl;
				break;
			case 4:
				cout << green << "It is " << work_date.NumberOfWeekInYear() << " in this year." << endl;
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
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
				cout << red + "->  " << light_blue + types[i] << endl;
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
				//Sortlist();
				break;
			case 2:
				end = true;
				break;
			}
		}
	}
}
