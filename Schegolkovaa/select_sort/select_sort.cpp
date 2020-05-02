// select_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


template<class T>
void selectSort(T a[], long size) 
{
	long i, j, k;
	T x;

	for (i = 0; i < size; i++)            // i - номер текущего шага
	{        
		k = i; x = a[i];

		for (j = i + 1; j < size; j++)  // цикл выбора наименьшего элемента
			if (a[j] < x) 
			{
				k = j; x = a[j];       // k - индекс наименьшего элемента
			}

		a[k] = a[i]; a[i] = x;        // меняем местами наименьший с a[i]
	}
}