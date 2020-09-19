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
        dates.InsertionSort();
        cout << dates.GetList() << endl;
    }
    catch (logic_error e)
    {
        cout << e.what();
    }
    return 0;
}
