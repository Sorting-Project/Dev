
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


void GnomeSort(int *arr, int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

void print(int *arr, int n, string title)
{
    cout << title << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
    setlocale(0, "russian");

    int n;
    cout << "Сколько элементов сгенерить?: ";
    cin >> n;

    int* arr;
    arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 90 + 10;

    print(arr, n, "Иходный массив");

    GnomeSort(arr, n);
    print(arr, n, "Результат гомьей сортировки");

    delete[] arr;
    return 0;
}
