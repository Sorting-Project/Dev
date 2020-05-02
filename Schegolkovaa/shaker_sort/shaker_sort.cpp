// shaker_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
void shakersort(int* l, int* r) 
{
	int sz = r - l;
	if (sz <= 1) return;
	bool b = true;
	int* beg = l - 1;
	int* end = r - 1;
	while (b) 
	{
		b = false;
		beg++;
		for (int* i = beg; i < end; i++) 
		{
			if (*i > *(i + 1)) 
			{
				swap(*i, *(i + 1));
				b = true;
			}
		}
		if (!b) break;
		end--;
		for (int* i = end; i > beg; i--) 
		{
			if (*i < *(i - 1)) {
				swap(*i, *(i - 1));
				b = true;
			}
		}
	}
}
