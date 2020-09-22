#include "Connection.h"

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
				//DateAndTime();
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
