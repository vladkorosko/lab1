#include "NewFunctions.h"

void menu()
{
	string types[4]
	{
		"Interactive dialog mode;",
		"Demonstrative mode;",
		"Benchmark;",
		"Exit."
	};
	int position = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		cout << blue + "    Choose the mode:" << endl;
		for (int i = 0; i < 4; i++)
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
					else position = 3;
				}

				if ((int)key == 80)
				{
					if (position < 3)
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
				interactive_mode();
				break;
			case 1:
				demo();
				break;
			case 2:
				bench();
				break;
			case 3:
				end = true;
				break;
			}
		}
	}
}
