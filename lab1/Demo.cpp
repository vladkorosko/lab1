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


}