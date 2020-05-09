#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &vec, int size)
{
	int tmp;

	for (int i = 0; i < size - 1; ++i) // i - номер прохода
	{
		for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
		{
			if (vec[j + 1] < vec[j])
			{
				tmp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = tmp;
			}
		}
	}
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
	bubbleSort (vec, vec.size());
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}
