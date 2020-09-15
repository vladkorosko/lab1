#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("+2: 2020.10.18; 10:00:30");
        cout << a;
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
