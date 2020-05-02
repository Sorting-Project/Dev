// Sort_count_and_select.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>

using namespace std;

template<typename T>
void SelectionSort(T array[], const size_t size)
{
	for (size_t idx_i = 0; idx_i < size - 1; idx_i++)
	{
		size_t min_idx = idx_i;
		for (size_t idx_j = idx_i + 1; idx_j < size; idx_j++)
			if (array[idx_j] < array[min_idx])
				min_idx = idx_j;
		if (min_idx != idx_i)
			swap(array[idx_i], array[min_idx]);
	}
}

void CountingSort(int* arr, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > k) k = arr[i];
	int c[k] = { 0 };
	for (int i = 0; i < n; i++)
		c[arr[i]] = c[arr[i]] + 1;
	int b = 0;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < c[i]; j++)
		{
			arr[b] = i;
			b = b + 1;
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	CountingSort(a, n);
	cout << "Сортировка подсчётом: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	a[n] = 0;
	SelectionSort(a, n);
	cout << "Сортировка выбором: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}

