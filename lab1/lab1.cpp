#include "SortList.h"
#include "NewFunctions.h"

int main()
{
    SortList<int> a;
    vector<int> c = { 1,2,3,4,5,6,7,8 };
    cout << c;
    SortList<int> b(c);
    cout << b.GetList();
    SortList<int> d(10);
    d.AutoGenerate();
    cout << d.GetList();
    d.BubbleSort();
    cout << d.GetList();
    return 0;
}
