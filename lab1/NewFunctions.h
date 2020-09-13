#pragma once
#include"SortList.h"

template <typename T>

ostream& operator<<(ostream& s, vector<T> l)
{
	s << " ";
	for (int i = 0; i < l.size(); i++)
		s << l[i] << " ";
	s << endl;
	return s;
}

