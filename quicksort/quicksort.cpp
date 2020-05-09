#include "pch.h"
#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;
void quicksort(vector<int> &vec, int begin0, int end0/*int b, int e, int *arr*/)
{
	int l = begin0, r = end0;
	int piv = vec[(l + r) / 2]; // Опорным элементом для примера возьмём средний
	while (l <= r)
	{
		while (vec[l] < piv)
			l++;
		while (vec[r] > piv)
			r--;
		if (l <= r)
			swap(vec[l++], vec[r--]);
	}
	if (begin0 < r)
		quicksort(vec, begin0, r);
	if (end0 > l)
		quicksort(vec, l, end0);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "введите числа, которые хотите отсортировать (для окончания ввода чисел, нажмите на любой знак, который не является числом)" << endl;
	vector <int> vec;
	int h;
	while (cin >> h)
		vec.push_back(h);
	for (size_t i = 0; i < vec.size(); i++) cout << vec[i] << endl;
	quicksort(vec, 0, vec.size() - 1);
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}
