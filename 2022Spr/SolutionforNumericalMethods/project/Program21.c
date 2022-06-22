/********************************************************************************
 * Description  :
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-04-19 21:32:27
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-04-19 22:26:12
 * FilePath     : \\project\\Program21\\Program21.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

#define f(x, y) ((y) * (sin((acos(-1)) * (x))))
#define y_0 1

int main()
{
    int n;
    double a, b;
    double y_1, y_2, k_1, k_2;
    printf("\nInput n value:  ");
    scanf("%d", &n);
    printf("\nInput a & b value:  ");
    scanf("%lf%lf", &a, &b);

    double h = (b - a) / n;
    y_1 = y_0;
    for (int k = 1; k <= n; k++)
    {
        k_1 = f(a + h * (k-1), y_1);
        k_2 = f(a + h * (k-1) + h / 2, y_1 + h / 2 * k_1);
        y_2 = y_1 + h * k_2;
        printf("\ny_%d = %lf\n", k, y_2);
        y_1 = y_2;
    }
    return 0;
}