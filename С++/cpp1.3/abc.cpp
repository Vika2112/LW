#include <cstdio>

int main()
{
    int a = 0; // Первое число
    int b = 0; // Второе число
    int c = 0; // Третье число
    std::puts(" Please, write a, b, c:"); //Вводим числа a, b, c
    std::scanf("%d %d %d", &a, &b, &c); // Сканируем все три числа
    std::printf("The sum of the numbers is:\n%d + %d + %d = %d", a, b, c, a+b+c);// Сумма чисел равна:
}