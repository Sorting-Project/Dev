// bitonicsort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "bitonicsort.h"
#include <algorithm>
using namespace std;
void bitseqsort(int* l, int* r, bool inv)
{
	if (r - l <= 1) return;
	int *m = l + (r - l) / 2;
	for (int *i = l, *j = m; i < m && j < r; i++, j++) 
	{
		if (inv ^ (*i > *j)) swap(*i, *j);
	}
	bitseqsort(l, m, inv);
	bitseqsort(m, r, inv);
}
void makebitonic(int* l, int* r) 
{
	if (r - l <= 1) return;
	int *m = l + (r - l) / 2;
	makebitonic(l, m);
	bitseqsort(l, m, 0);
	makebitonic(m, r);
	bitseqsort(m, r, 1);
}
void bitonicsort(int* l, int* r) 
{
	int n = 1;
	int inf = *max_element(l, r) + 1;
	while (n < r - l) n *= 2;
	int* a = new int[n];
	int cur = 0;
	for (int *i = l; i < r; i++)
		a[cur++] = *i;
	while (cur < n) a[cur++] = inf;
	makebitonic(a, a + n);
	bitseqsort(a, a + n, 0);
	cur = 0;
	for (int *i = l; i < r; i++)
		*i = a[cur++];
	delete a;
}
int main()
{
    std::cout << "Hello World!\n"; 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
