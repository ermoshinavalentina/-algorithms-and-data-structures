
#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    float R;
    float x;
    float y;
    printf_s("Введите R = ");
    if (x >= -10 and x < 0) y = -x;
    else
        if (x >= 0 and x < 3) y = -R;
        else
            if (x >= 3 and x < 6) y = R;
            else y = 0;
    printf_s("Значение функции = ");
    //printf_s (y);
}
