#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a(2,18262,10,10,10);
        Date b("+3: 2019.9.19; 10:00:30");
        //.ChangeUTC(-12);
        cout << a.GetDateInDays();
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
