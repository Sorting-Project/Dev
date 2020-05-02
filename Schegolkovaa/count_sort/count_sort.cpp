// count_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>

using namespace std;

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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	CountingSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
