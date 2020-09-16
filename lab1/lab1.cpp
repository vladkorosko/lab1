#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("+12: 1970.01.1; 10:00:30");
        a.ChangeUTC(-12);
        cout << a;
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
