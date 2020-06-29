#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; //использование пространства имён std
const int N = 20; //константа

int InterpolSearch(int A[], int key) //функция интерполяционный поиск
{
    int mid, left = 0, right = N - 1; //среднее и левое значение 0, правое n - 1
    while (A[left] <= key && A[right] >= key) //пока левое значение меньше чем ключ  и правое больше чем ключ
    {
        mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]); //вычислить среднее значение
        if (A[mid] < key) left = mid + 1; //если  среднее значение меньше ключа, левое значение = среднее + 1
        else if (A[mid] > key) right = mid - 1; //если среднее значение больше ключа, правое значение = среднее + 1
        else return mid; //иначе вернуть среднее значение 
    }
    if (A[left] == key) return left; //если левое значение равно ключу, вернуть его
    else return -1; //иначе вернуть -1
}

//главная функция
int main()
{
    
    setlocale(LC_ALL, "Rus"); //русская кодировка
    int i, key; 
    srand(time(NULL)); //обнуление системного времени
    int A[N] = {}; //пустой массив
    for (int i = 0; i < N; i++)
    {
        A[i] = rand(); //заполнение массива случайными числами
    }
    cout << "Искомый элемент > "; cin >> key; //ввод ключа
    cout << "Исходный массив: ";
    for (i = 0; i < N; i++) cout << A[i] << " "; //вывод массива
    if (InterpolSearch(A, key) == -1) cout << "\nЭлемент не найден";
    else cout << "\nНомер элемента: " << InterpolSearch(A, key) + 1; //вывод номера элемента
    system("pause>>void");
}
