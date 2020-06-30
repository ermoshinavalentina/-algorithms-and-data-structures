#include "pch.h"
#include <iostream>
#include <stack>
using namespace std;

//главная функция






void main()
{
	setlocale(LC_ALL, "Russian");
	stack <int> S; //создание стека S типа int
	char number; int value;
	do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Получить верхний элемент" << endl;
		cout << "4. Узнать размер стека" << endl;
		cout << "0. Выйти" << endl;
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{
		case '1': //добавление элемента
			cout << "Значение > "; cin >> value;
			S.push(value); cout << endl << "Элемент добавлен в стек\n\n";
			break;
			//-----------------------------------------------
		case '2': //удаление элемента
			if (S.empty() == true) cout << "\nСтек пуст\n\n";
			else
			{
				S.pop(); cout << endl << "Элемент удален из стека\n\n";
			} break;
			//-----------------------------------------------
		case '3': //вывод верхнего элемента
			if (S.empty() == true) cout << "\nСтек пуст\n\n";
			else cout << "\nВерхний элемент стека: " << S.top() << "\n\n";
			break;
			//-----------------------------------------------
		case '4': //вывод размера стека
			if (S.empty() == true) cout << "\nСтек пуст\n\n";
			else cout << "\nРазмер стека: " << S.size() << "\n\n";
			break;
			//-----------------------------------------------
		case '0': break; //выход
		default: cout << endl << "Команда не определенная\n\n";
			break;
		}
	} while (number != '0');

	system("pause");
}
