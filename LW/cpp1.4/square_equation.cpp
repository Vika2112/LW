#include <cstdio>
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0; // Первый коэффициент уравнения
    float b = 0; // Второй коэффициент уравнения
    float c = 0; // Третий коэффициент уравнения
    float d = 0; //  Дискриминант  
    float x1 = 0; //  Первый корень уравнения
    float x2 = 0; //  Второй корень уравнения
    
    std::puts("We find x by the reduced formula: ax^2+bx+c=0");// Находим x по заданной формуле
    std::puts("Write a:"); //Вводим коэфициент a
    std::scanf("%f", &a);

    std::puts("Write b:"); //Вводим коэфициент b
    std::scanf("%f", &b); 
    std::puts("Write c:"); //Вводим коэфициент c
    std::scanf("%f", &c); 

  

    d = (b * b) - (4 * a * c); // Находим дискриминант

    if (abs(d) == d) // Если дискриминант больше или равен 0, то находим корни уравнения
    {

        x1 = ((-b) + sqrt(d)) / (2 * a); // Расчитываем первый корень
        x2 = ((-b) - sqrt(d)) / (2 * a); // Расчитываем второй корень

        std::printf("Solution:\nx1 = %f\nx2 = %f", x1, x2); // Выводим корни 
    }
    else // Если дискриминант отрицательный то  корней нет
    {
        std::puts("No roots, negative discriminant");
    }
}
