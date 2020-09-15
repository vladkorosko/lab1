﻿#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        Date a("0: 2020.9.15; 0:0:0");
        cout << a.GetNameOfDay();
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
