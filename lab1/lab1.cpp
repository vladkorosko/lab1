#include "Connection.h"

int main()
{
    Menu();
    Date a("+2: 2020.09.22; 00:00:00");
    cout << a.NumberOfWeekInMonth();
    return 0;
}
