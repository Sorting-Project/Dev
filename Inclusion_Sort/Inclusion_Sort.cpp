// Inclusion_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void inclusionSort(vector<int> &vec, int size)
{
	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = vec[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while ((index > 0) && (vec[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			vec[index] = vec[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		vec[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}
int main(){
setlocale(LC_ALL, "Russian");
cout << "введите числа, которые хотите отсортировать (для окончания ввода чисел, нажмите на любой знак, который не является числом)" << endl;
vector <int> vec;
int h;
while (cin >> h)
vec.push_back(h);
for (size_t i = 0; i < vec.size(); i++) cout << vec[i] << endl;
inclusionSort(vec, vec.size());
for (auto i : vec)
cout << i << " ";
cout << endl;
}
