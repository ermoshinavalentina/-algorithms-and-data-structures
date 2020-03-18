// Console2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    float R;
    float x;
    float y;
    std::cout << "Введите R = " << std::endl;
    std::cin >> R;
    std::cout << "Введите x = " << std::endl;
    std::cin >> x;
    std::cout << "Введите y = " << std::endl;
    std::cin >> y;
    if ((x >= -10 and x < 0) || (x >= 0 and x < 3) || (x >= 3 and x < 6))
       printf_s("Точка попадает в область");
    else  printf_s("Точка не попадает в область");
}


