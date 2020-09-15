#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("+2: 2020.09.15; 00:00:00");
        cout << a.GetNameOfDay() << endl << a.GetDate();
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
