#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>


int binarysearch(int a, int mass[], int n);
void InsertionSort(int n, int mass[]);

int main()
{
    setlocale(LC_ALL, "Rus");
    //ввод N
    int N, a;
    printf("Введите число элементов массива: ");
    scanf_s("%d", &N);
    //выделение памяти под массив
    int* mass;
    mass = (int*)malloc(N * sizeof(int));
    //ввод элементов массива
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        mass[i] = rand();
    //сортировка вставками
    InsertionSort(N, mass);
    //вывод отсортированного массива на экран
    printf("Отсортированный массив:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");
    //ввод искомого элемента
    printf("Введите искомый элемент: ");
    scanf_s("%d", &a);
    int k;
    //двоичный поиск
    k = binarysearch(a, mass, N);
    if (k != -1)
    {
        printf("Индекс элемента массива %d\n", k);
    }
    else
        printf("Искомый элемент не найден!\n");
    //освобождение памяти
    free(mass);
    _getch();
    return 0;
}

int binarysearch(int a, int mass[], int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

//сортировка вставками
void InsertionSort(int n, int mass[])
{
    int newElement, location;

    for (int i = 1; i < n; i++)
    {
        newElement = mass[i];
        location = i - 1;
        while (location >= 0 && mass[location] > newElement)
        {
            mass[location + 1] = mass[location];
            location = location - 1;
        }
        mass[location + 1] = newElement;
    }
}