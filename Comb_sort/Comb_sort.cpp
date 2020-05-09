// Comb_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void comb_sort(vector<int> &vec, int size)
{
	int temp, k;
	int s = size; // готовим начальный шаг
	long long count = 0;
	while (size > 1) {
		s /= 1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
										// и легкие элементы в хвосте переносятся в первые 20% 
		if (s < 1) s = 1; // 0 быть не может, присвоим 1
		k = 0; // нет перестановок
		for (int i = 0; i + s < size; ++i) { // двигаемся, пока сравниваемый элемент (на s от текущего) в массиве
			if (vec[i] / 10 > vec[i + s] / 10) {
				temp = vec[i];
				vec[i] = vec[i + s];
				vec[i + s] = temp;
				k = i;
			}
			++count;
		}
		if (s == 1) // шаг 1, как в обычном пузырьке. Включаем контроль	
			size = k + 1;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "введите числа, которые хотите отсортировать (для окончания ввода чисел, нажмите на любой знак, который не является числом)" << endl;
	vector <int> vec;
	int h;
	while (cin >> h)
		vec.push_back(h);
	for (size_t i = 0; i < vec.size(); i++) cout << vec[i] << endl;
	comb_sort(vec, vec.size());
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}
