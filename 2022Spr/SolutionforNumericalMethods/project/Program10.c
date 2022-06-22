/********************************************************************************
 * Description  :
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-04-19 16:20:43
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-04-20 16:15:23
 * FilePath     : \\project\\Program10\\Program10.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

#define x_0 0.8
#define y_0 0.6
#define epsilon 0.00001
#define f(x, y) (pow((x), 2) + pow((y), 2) - 1)
#define g(x, y) (pow((x), 3) - (y))
#define f_x(x, y) (2 * (x))
#define f_y(x, y) (2 * (y))
#define g_x(x, y) (3 * pow((x), 2))
#define g_y(x, y) (-1)
#define MAXREPT 100

int main()
{
    double x_1 = x_0, x_2, y_1 = y_0, y_2;
    for (int k = 1; k <= MAXREPT; k++)
    {
        x_2 = x_1 + (f(x_1, y_1) * g_y(x_1, y_1) - g(x_1, y_1) * f_y(x_1, y_1)) / (g_x(x_1, y_1) * f_y(x_1, y_1) - f_x(x_1, y_1) * g_y(x_1, y_1));
        y_2 = y_1 + (g(x_1, y_1) * f_x(x_1, y_1) - f(x_1, y_1) * f_x(x_1, y_1)) / (g_x(x_1, y_1) * f_y(x_1, y_1) - f_x(x_1, y_1) * g_y(x_1, y_1));
        // double MAX = (fabs(x_2 - x_1) > fabs(y_2 - y_1)) ? fabs(x_2 - x_1) : fabs(y_2 - y_1);
        if (fabs(x_2 - x_1) < epsilon && fabs(y_2 - y_1) < epsilon)
        {
            printf("\nk = %d\n", k);
            printf("\nx_k = %lf, y_k = %lf\n", x_2, y_2);
            break;
        }
        else
        {
            x_1 = x_2;
            y_1 = y_2;
            continue;
        }
        printf("\n精度过高或不收敛\n");
    }
    return 0;
}