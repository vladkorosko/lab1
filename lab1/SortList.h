#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<random>
#include<time.h>
#include<typeinfo>
#include<sstream>
#include<iomanip>

using namespace std;

bool operator==(const vector<int>& v1, const vector<int>& v2);
bool operator>(vector<int>& v1, vector<int>& v2);
bool operator<(vector<int>& v1, vector<int>& v2);

template<typename T>
class SortList
{
private:
	vector<T> list;

	void qs(int first, int last)
	{
		T x = list[first];
		int i = first, j = last;
		do
		{
			while (list[i] < x)
				i++;
			while (list[j] > x)
				j--;
			if (i <= j)
			{
				if (i < j)
					swap(list[i], list[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (first < j)
			qs(first, j);
		if (last > i)
			qs(i, last);
	}

	void merge(int index_of_first_element_of_first_part, int index_of_last_element_of_first_part, int index_of_last_element_second_part)
	{
		int i, j, k;
		int n1 = index_of_last_element_of_first_part - index_of_first_element_of_first_part + 1;
		int n2 = index_of_last_element_second_part - index_of_last_element_of_first_part;

		vector<T> First_array(n1);
		vector<T> Second_array(n2);

		for (i = 0; i < n1; i++)
			First_array[i] = list[index_of_first_element_of_first_part + i];
		for (j = 0; j < n2; j++)
			Second_array[j] = list[index_of_last_element_of_first_part + 1 + j];

		i = 0;
		j = 0;
		k = index_of_first_element_of_first_part;
		while (i < n1 && j < n2)
		{
			if (First_array[i] < Second_array[j])
			{
				list[k] = First_array[i];
				i++;
			}
			else
			{
				list[k] = Second_array[j];
				j++;
			}
			k++;
		}

		while (i < n1)
		{
			list[k] = First_array[i];
			i++;
			k++;
		}

		while (j < n2)
		{
			list[k] = Second_array[j];
			j++;
			k++;
		}
	}

	void merge_sort(int start, int finish)
	{
		if (start < finish)
		{
			int m = start + (finish - start) / 2;
			merge_sort(start, m);
			merge_sort(m + 1, finish);
			merge(start, m, finish);
		}
	}
public:
	SortList() {};

	SortList(int n)
	{
		vector<T> a(n);
		list = a;
	}

	void Add(T val)
	{
		list.push_back(val);
	}

	void Del(int index)
	{
		if (index < list.size() && index >= 0)
			list.erase(list.begin() + index);
		else throw logic_error("List index out of range: " + to_string(index) + '.');
	}

	SortList(vector<T> new_list)
	{
		for (auto i : new_list)
			Add(i);
	}

	void operator=(SortList b)
	{
		list = b.list;
	}

	vector<T> GetList() const
	{
		return list;
	}

	void BubbleSort()
	{
		for (int i = 0; i < list.size(); i++)
			for (int j = i + 1; j < list.size(); j++)
			{
				if (list[i] > list[j])
					swap(list[i], list[j]);
			}
	}

	void SelectionSort()
	{
		int min_ind;
		for (int i = 0; i < list.size() - 1; i++)
		{
			min_ind = i;
			for (int j = i; j < list.size(); j++)
				if (list[j] < list[min_ind])
					min_ind = j;
			swap(list[min_ind], list[i]);
		}
	}

	void InsertionSort()
	{
		int j;
		T value;
		for (int i = 0; i < list.size(); i++)
		{
			value = list[i];
			j = i - 1;
			while (j >= 0 && list[j] > value)
			{
				list[j + 1] = list[j];
				j--;
			}
			list[j + 1] = value;
		}
	}

	void QuickSort()
	{
		qs(0, list.size() - 1);
	}

	void MergeSort()
	{
		merge_sort(0, list.size() - 1);
	}
};

