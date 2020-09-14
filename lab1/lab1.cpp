#include "NewFunctions.h"

int main()
{
    vector<int> c = { 2,3,4,5,6,1,34,5,6 };
    cout << c;
    SortList<int> b = c;
    cout << b.GetList();
    b.BubbleSort();
    cout << b.GetList();
    return 0;
}
