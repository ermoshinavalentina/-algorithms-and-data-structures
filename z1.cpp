// z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");
    float a;
    std::cout << "Введите а \n";
    std::cin >> a;
    double z1 = 0;
    double z2 = 0;
    z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a)) / (cos(a) + 1 - 2 * sqrt(sin(2 * a)));
    z2 = (tan(3 * a));
    std::cout << "Значение функции z1 = " << z1 << " \n " << "Значение функции z2 = " << z2;
    
}

