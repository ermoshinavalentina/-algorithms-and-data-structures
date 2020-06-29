#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>


int binarysearch(int a, int mass[], int n); //объявление функции бинарного поиска
void InsertionSort(int n, int mass[]); //объявление функции сортировки вставками

int main()
{
    setlocale(LC_ALL, "Rus"); //установить русскую кодировку
    //ввод N
    int N, a;
    printf("Введите число элементов массива: ");
    scanf_s("%d", &N);
    //выделение памяти под массив
    int* mass;
    mass = (int*)malloc(N * sizeof(int));
    //заполнение элементов массива случайными значениями
    srand(time(NULL)); //обнуление системного времени
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
    if (k != -1) //если значение k не равно -1
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

int binarysearch(int a, int mass[], int n) //функция бинарного поиска
{
    int low, high, middle; //наименьшее, наибольшее и среднее значение
    low = 0; //наименьшее значение 0
    high = n - 1; //наибольшее значение n - 1
    while (low <= high) //пока наименьшее значение меньше или равно наибольшему
    {
        middle = (low + high) / 2; //среднее значение равно среднему аримфетическому наименьшего и наибольшего значения
        if (a < mass[middle]) //если а меньше среднего значения
            high = middle - 1; //наибольшее значение = среднее - 1
        else if (a > mass[middle]) //если а больше среднего значения
            low = middle + 1; //наименьшее = среднее + 1
        else
            return middle; //иначе вернуть среднее значение 
    }
    return -1; //вернуть - 1
}

//сортировка вставками
void InsertionSort(int n, int mass[]) 
{
    int newElement, location; //новый элемент, расположение

    for (int i = 1; i < n; i++) 
    {
        newElement = mass[i]; //новый элемент равен i элементу массива 
        location = i - 1; //расположение на единицу меньше
        while (location >= 0 && mass[location] > newElement) //пока расположение элемента больше или равно 0 и больше нового элемента
        {
            mass[location + 1] = mass[location]; 
        }
        mass[location + 1] = newElement; 
    }
}
