#include <iostream>
#include <locale>
int main() {
	setlocale(LC_CTYPE, "rus");
	float R, x, y;
	printf_s("Введите R=");
	scanf_s("%f", &R);
	printf_s("Введите x=");
	scanf_s("%f", &x);
	printf_s("Введите y=");
	scanf_s("%f", &y);
	if ((y >= 0 && x * x + y * y <= R * R) || (y <= x && y >= -R && x <= 0))
	{
		printf_s("Попадает");
	}
	else
		printf_s("Не попадает");
}

//график

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


