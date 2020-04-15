#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N = 20;

int InterpolSearch(int A[], int key)
{
    int mid, left = 0, right = N - 1;
    while (A[left] <= key && A[right] >= key)
    {
        mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
        if (A[mid] < key) left = mid + 1;
        else if (A[mid] > key) right = mid - 1;
        else return mid;
    }
    if (A[left] == key) return left;
    else return -1;
}

//главная функция
int main()
{
    
    setlocale(LC_ALL, "Rus");
    int i, key;
    srand(time(NULL));
    int A[N] = {};
    for (int i = 0; i < N; i++)
    {
        A[i] = rand();
    }
    cout << "Искомый элемент > "; cin >> key; //ввод ключа
    cout << "Исходный массив: ";
    for (i = 0; i < N; i++) cout << A[i] << " "; //вывод массива
    if (InterpolSearch(A, key) == -1) cout << "\nЭлемент не найден";
    else cout << "\nНомер элемента: " << InterpolSearch(A, key) + 1;
    system("pause>>void");
}
