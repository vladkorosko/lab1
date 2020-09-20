#include "NewFunctions.h"

int main()
{
    srand(time(NULL));
    try
    {
        vector<Date> a(10);
        for (auto& i : a)
            i.AutoGenerate();
        SortList<Date> dates(a); 
        cout << dates.GetList() << endl;
        dates.QuickSort();
        cout << dates.GetList() << endl;
        cout << endl;
        Date c("+3: 10020.09.20; 21:29:59");
        cout << c.Stats(1);

    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
