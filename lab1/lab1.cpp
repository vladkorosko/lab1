#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("+3: 2020.9.19; 10:00:20");
        Date b("+3: 2019.9.19; 10:00:30");
        //.ChangeUTC(-12);
        cout << b - (a - b);
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
