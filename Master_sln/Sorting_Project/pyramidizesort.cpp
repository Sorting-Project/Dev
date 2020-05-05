
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


void pyramidize(int *arr, int root, int bottom)
{
    int maxChild;
    bool stop = 0;

    while ((root * 2 <= bottom) && (!stop))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (arr[root * 2] < arr[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (arr[root] > arr[maxChild])
        {
            swap(arr[root], arr[maxChild]);
            root = maxChild;
        }
        else
            stop = 1;
    }
}

void heapSort(int *arr, int n)
{
    int tmp;
    for (int i = (n / 2) - 1; i >= 0; i--)
        pyramidize(arr, i, n - 1);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        pyramidize(arr, 0, i - 1);
    }
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

    heapSort(arr, n);
    print(arr, n, "Результат сортировки пирамидкой");

    delete[] arr;
    return 0;
}
