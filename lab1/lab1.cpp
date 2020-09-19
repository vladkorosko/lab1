#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("+2: 2020.09.19; 10:00:30");
        Date b("+3: 2019.9.19; 10:00:30");
        //.ChangeUTC(-12);
        cout << a-b;
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
