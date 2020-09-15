#include "NewFunctions.h"

int main()
{
    try
    {
        Date a("+02: 2020.02.02; 08:59:59");
        cout << a.GetDate();
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
