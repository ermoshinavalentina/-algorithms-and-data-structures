#include <iostream> //поток ввода вывода данных

int fibonacci(int number) //функция вычисления числа Фибоначчи
{
    if (number == 0) //если число = 0
        return 0; // базовый случай (условие завершения)
    if (number == 1) //если число = 1
        return 1; // базовый случай (условие завершения)
    return fibonacci(number - 1) + fibonacci(number - 2); //возвращаемое значение 
}

// Выводим первые 13 чисел Фибоначчи
int main()
{
    for (int count = 0; count < 13; ++count)
        std::cout << fibonacci(count) << " ";

    return 0;
}
