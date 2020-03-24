#include <iostream>
#include <stdlib.h>
#include <windows.h> 

char* Rus(const char* text);

using namespace std;

int main(int argc, char* argv[])
{
    double Xn, Xk, dX, a, b, c, x, F;
    cout << Rus("Введите Xn, Xk, dX,  a, b, c\n");
    scanf_s("%lf%lf%lf%lf%lf%lf", &Xn, &Xk, &dX, &a, &b, &c);
    int a1, b1, c1, F1, i;
    a1 = (int)a;
    b1 = (int)b;
    c1 = (int)c;
    cout << "a=" << a << Rus(" целая часть a1=") << a1 << endl;
    cout << "b=" << b << Rus(" целая часть b1=") << b1 << endl;
    cout << "c=" << c << Rus(" целая часть c1=") << c1 << endl;
    cout << "i| a | b | c | x | F |\n" << endl;
    x = Xn;
    i = 1;
    while (x <= Xk)

    {
        if ((x >= -10 and x < 0) || (x >= 0 and x < 3) || (x >= 3 and x < 6)) F = -a * x * x - b;
        else if (x > -10 && c == 0) F = (x - a) / x;
        {
            if (c == 0) cout << i << Rus("| F= Бесконечность x=") << x << " c=" << c << endl;

            else F = -x / c;
            F1 = (int)F;
            if (((a1 | b1) != 0) ^ ((a1 | c1) != 0))
                cout << i << "| " << a << " | " << b << " | " << c << " | " << x << " | " << F << endl;
            else cout << i << "| " << a << " | " << b << " | " << c << " | " << x << " | " << F1 << endl;
        }
        x += dX;
        i++;
    }
    system("PAUSE");
    return 0;
}

char bufRus[256];
char* Rus(const char* text)
{
    CharToOemA(text, bufRus);
    return bufRus;
}