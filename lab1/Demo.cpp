#include"Connection.h"

void demo()
{
	cout << blue << "Hello user. Now show you what can this program." << endl;

	cout << "Let`s start from Date class. Now i create empty object Date d." << endl;
	Date d;
	cout << green << d << endl;
	pause();

	cout << blue << "Now i try to create next date: +2: 1990.23.59; 15:30:120 (Right format: UTC: yyyy.mm.dd; hh:mm:ss)." << endl;
	try {
		d = Date("+2: 1990.23.59; 15:30:120");
		cout << green << d << endl;
	}
	catch (logic_error e)
	{
		cout << red << e.what() << endl;
	}
	pause();

	cout << blue << "Now I create random date." << endl;
	d.AutoGenerate();
	cout << green << d << endl;
	pause();

	cout << blue << "Now I create right date(+0: 2020.09.26; 15:30:12) and change UTC to +12." << endl;
	d = Date("+0: 2020.09.26; 15:30:12");
	cout << green << d << endl;
	d.ChangeUTC(+12);
	cout << d << endl;
	pause();

	cout << blue << "Now i count number of week in month and in year." << endl;
	cout << green << "It is " << d.NumberOfWeekInMonth() << " in this month." << endl;
	cout << green << "It is " << d.NumberOfWeekInYear() << " in this year." << endl;
	pause();

	cout << blue << "Now i show you statistic adout current day." << endl;
	vector<double> stats = d.Stats();
	cout << setfill(' ');
	cout << green << setw(12) << "Monday: " << setw(5) << setprecision(5) << stats[4] * 100 << '%' << endl;
	cout << green << setw(12) << "Tuesday: " << setw(5) << setprecision(5) << stats[5] * 100 << '%' << endl;
	cout << green << setw(12) << "Wednesday: " << setw(5) << setprecision(5) << stats[6] * 100 << '%' << endl;
	cout << green << setw(12) << "Thirsday: " << setw(5) << setprecision(5) << stats[0] * 100 << '%' << endl;
	cout << green << setw(12) << "Friday: " << setw(5) << setprecision(5) << stats[1] * 100 << '%' << endl;
	cout << green << setw(12) << "Saturday: " << setw(5) << setprecision(5) << stats[2] * 100 << '%' << endl;
	cout << green << setw(12) << "Sunday: " << setw(5) << setprecision(5) << stats[3] * 100 << '%' << endl;
	pause();

	cout << blue << "Now I create new date(+0: 2020.09.29; 23:59:59) and count difference between it and first date." << endl;
	Date d1("+0: 2020.09.29; 23:59:59");
	TimeDifference diff = d1 - d;
	cout << green << diff << endl;
	pause();
	cout << blue << "Now I decrease first and increase second date by previous difference." << endl;
	cout << light_blue << "First date: " + d.GetDate() << endl;
	cout << green << "Difference: " + (d - diff).GetDate() << endl;
	cout << light_blue << "Second date: " + d1.GetDate() << endl;
	cout << green << "Sum: " + (d1 + diff).GetDate() << endl;

	pause();

	cout << blue << "This all for Date. For more information choose interactive mode and check program by yourself." << endl;
	pause();
	cout << "Now I show you function for SortList.\nFor demonstration I choose SortList<int> but it work in same way with other types. Now I create random SortList<int> with 10 elements." << endl;
	SortList<int> list(AutoGenerateInt(10));
	cout << green << list.GetList() << endl;
	pause();

	cout << blue << "Now i add 10 to the end of list. Then I delete it." << endl;
	list.Add(10);
	cout << green << list.GetList() << endl;
	list.Del(10);
	cout << green << list.GetList() << endl;
	pause();

	cout << blue << "Now i sort list in different types and show you result." << endl;
	SortList<int> list1 = list;
	cout << light_blue << "Before: " << list.GetList() << endl;
	list1.BubbleSort();
	cout << green << "After bubble sorting: " << list1.GetList() << endl;
	list1 = list;
	list1.SelectionSort();
	cout << "After selection sorting: " << list1.GetList() << endl;
	list1 = list;
	list1.InsertionSort();
	cout << "After insertion sorting: " << list1.GetList() << endl;
	list1 = list;
	list1.QuickSort();
	cout << "After quick sorting: " << list1.GetList() << endl;
	list1 = list;
	list1.MergeSort();
	cout << "After Bubble sorting: " << list1.GetList() << endl;
	pause();

	cout << blue << "This all. Goodbye!" << endl;
	pause();
}