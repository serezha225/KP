#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>
double calc_q(double x)
{
    if (x < 140.0) {
        return (x - 140.0) * (x - 140.0) / 18.0 + 8.0;
    }
    else if (x <= 180.0) {
        return 2.0 * sqrt(x - 160.0 + 20.0) + 42.0;
    }
    else {
        return 3.0 * (x - 180.0) + 60.0;
    }
}

int check(double q, double q_prev, double delt_q)
{
    if (fabs(q - q_prev) > delt_q) {
        return 1; 
    }
    return 0; 
}

int main()
{
    const double q0 = 50.94;   
    const double delt_q = 5.0;  
    double x, q;

    setlocale(LC_ALL, "Russian");

    printf("Введите температуру пара X (от 100 до 220 °C): \n");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    if (x < 100.0 || x > 220.0) {
        printf("Ошибка: значение X должно быть в диапазоне от 100 до 220 °C.\n");
        return 1;
    }

    q = calc_q(x);
    printf("Преобразованное показание Q = %.2f\n", q);

    if (check(q, q0, delt_q) == 1) {
        printf("Состояние: ПРЕДУПРЕЖДЕНИЕ (изменение больше допустимого)\n");
    }
    else {
        printf("Состояние: НОРМА\n");
    }

    return 0;
}