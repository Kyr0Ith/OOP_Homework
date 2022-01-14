/*
ИДЗ 1
Закрятин Касьян
Б9120-09.03.04прогин, подгруппа 4
Вариант 3

1) Вычислить биссектрисы треугольников по формулам
2) Вычислить значение функции y и z по формулам при различных вещественных типах данных (float и double). 
Параметр x вводится с клавиатуры. 
Вычисления следует выполнять с использованием промежуточных переменных.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Задание 1
    float a = 8.35, b = 10.6, c = 8.65;
    float Ba, Bb, Bc, p;
    
    p = a + b + c;
    Ba = (2*sqrt(b*c*p*(p-a)))/(b+c);
    Bb = (2*sqrt(a*c*p*(p-b)))/(a+c);
    Bc = (2*sqrt(b*a*p*(p-c)))/(b+a);
    
    cout << "Задание 1 \n";
    cout << Ba << '\n';
    cout << Bb << '\n';
    cout << Bc << '\n';
    
    //Задание 2
    float y, z, x;
    double y1, z1, x1;
    cout << "Введите x(float) \n";
    cin >> x;
    cout << "Введите x(double) \n";
    cin >> x1;
    
    a = 0; b = 0; c = 0; //Промежуточные переменные
    float d, f ,g;
    double a1, b1, c1, d1, f1;
    a = abs(x - 3.7);
    b = abs(a - 2.7);
    y = b - 1.7;
    
    c = sqrt(abs(x) - abs(y));
    d = abs(x - y);
    f = abs(x + y);
    z = c - d + f*x;
    cout << y << ' ' << z << '\n';
    
    
    a1 = abs(x1 - 3.7);
    b1 = abs(a1 - 2.7);
    y1 = b1 - 1.7;
    
    c1 = sqrt(abs(x1) - abs(y1));
    d1 = abs(x1 - y1);
    f1 = abs(x1 + y1);
    z1 = c1 - d1 + f1*x1;
    cout << y1 << ' ' << z1;
}