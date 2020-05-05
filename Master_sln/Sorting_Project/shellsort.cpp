#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <string.h>
// Функция сортировки Шелла
void shellSort(int *num, int size)
{
    int increment = 3; // начальное приращение сортировки
    while (increment > 0) // пока существует приращение
    {
        for (int i = 0; i < size; i++) // для всех элементов массива
        {
            int j = i; // сохраняем индекс и элемент
            int temp = num[i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (num[j - increment] > temp))
            { // пока отстоящий элемент больше текущего
                num[j] = num[j - increment]; // перемещаем его на текущую позицию
                j = j - increment; // переходим к следующему отстоящему элементу
            }
            num[j] = temp; // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1) // делим приращение на 2
            increment = increment / 2;
        else if (increment == 1) // последний проход завершён,
            break; // выходим из цикла
    }
}
using namespace std;
int main()
{
    int m[10];
    // Вводим элементы массива
    for (int i = 0; i < 10; i++)
    {
        printf("m[%d]=", i);
        scanf_s("%d", &m[i]);
    }
    shellSort(m, 10); // вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    for (int i = 0; i < 10; i++)
        printf ("%.2d ", m[i]);
    return 0;
}
