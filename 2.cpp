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
