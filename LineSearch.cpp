#include <iostream>
#include <ctime>
using namespace std;
int i, N;
//линейный поиск
int LineSearch(int A[], int key)
{
	for (i = 0; i < N; i++)
		if (A[i] == key) return i;
	return -1;
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int key, A[1000];
	srand(time(NULL));
	cout << "Размер массива > "; cin >> N;
	cout << "Искомый элемент > "; cin >> key;
	cout << "Исходный массив: ";
	for (i = 0; i < N; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << " ";
	}
	if (LineSearch(A, key) == -1) cout << "\nЭлемент не найден";
	else cout << "\nНомер элемента: " << LineSearch(A, key) + 1;
	system("pause>>void");
}