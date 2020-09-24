#include "Connection.h"

void SortListInt()
{
	SortList<int> work_list;
	const string types[10]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int index = 0;
			int element = 0;
			int number_of_elements = 0;
			string line = "";
			SortList<int> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter new element(integer)." << light_blue << endl;
					getline(cin, line);
					element = EnterNumber(line);
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<int>(AutoGenerateInt(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}

void SortListDouble()
{
	SortList<double> work_list;
	const string types[10]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int index = 0;
			double element = 0.0;
			int number_of_elements = 0;
			string line = "";
			SortList<double> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter new element(double)." << light_blue << endl;
					getline(cin, line);
					element = EnterDouble(line);
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<double>(AutoGenerateDouble(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}

void SortListChar()
{
	SortList<char> work_list;
	const string types[10]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int index = 0;
			char element = 0;
			int number_of_elements = 0;
			string line = "";
			SortList<char> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter new element(char)." << light_blue << endl;
					element = _getch();
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<char>(AutoGenerateChar(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}

void SortListString()
{
	SortList<string> work_list;
	const string types[10]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int index = 0;
			string element = "";
			int number_of_elements = 0;
			string line = "";
			SortList<string> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter new element(string)." << light_blue << endl;
					getline(cin, element);
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<string>(AutoGenerateString(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}

void SortListVectorInt()
{
	SortList<vector<int>> work_list;
	const string types[10]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 10; i++)
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
					else position = 9;
				}

				if ((int)key == 80)
				{
					if (position < 9)
						position++;
					else position = 0;
				}
			}
		}
		else
		{
			int index = 0;
			vector<int> element;
			int number_of_elements = 0;
			string line = "";
			SortList<vector<int>> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					for (int i = 0; i < number_of_elements; i++)
					{
						cout << blue + "Enter new element(integer)." << light_blue << endl;
						getline(cin, line);
						element.push_back(EnterNumber(line));
					}
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<vector<int>>(AutoGenerateVectorInt(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}

void SortListDate()
{
	SortList<Date> work_list;
	const string types[12]
	{
		"Add element;",
		"Remove element;",
		"Autogenerate list;",
		"Get list;",
		"Bubble sort;",
		"Insertion sort;",
		"Selection sort;",
		"Quick sort;",
		"Merge sort;",
		"Back."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose one of next operations:" << endl;
		for (int i = 0; i < 12; i++)
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
			int index = 0;
			Date element;
			int number_of_elements = 0;
			string line = "";
			SortList<Date> result;
			system("cls");
			try
			{
				switch (position)
				{
				case 0:
					cout << blue + "Enter new element(integer)." << light_blue << endl;
					getline(cin, line);
					element = Date(line);
					work_list.Add(element);
					pause();
					break;
				case 1:
					cout << blue + "Enter index." << light_blue << endl;
					getline(cin, line);
					index = EnterNumber(line);
					work_list.Del(index);
					pause();
					break;
				case 2:
					cout << blue + "Enter number of elements." << light_blue << endl;
					getline(cin, line);
					number_of_elements = EnterNumber(line);
					work_list = SortList<Date>(AutoGenerateDate(number_of_elements));
					pause();
					break;
				case 3:
					cout << green << work_list.GetList() << endl;
					pause();
					break;
				case 4:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 5:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 6:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 7:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 8:
					result = work_list;
					result.BubbleSort();
					cout << blue << setw(14) << "Before sorting: " << green;
					cout << work_list.GetList() << endl;
					cout << blue << setw(14) << "After sorting: " << green;
					cout << result.GetList() << endl;
					pause();
					break;
				case 9:
					end = true;
					break;
				default:
					break;
				}
			}
			catch (logic_error e)
			{
				cout << red << e.what() << endl;
				pause();
			}
		}
	}
}