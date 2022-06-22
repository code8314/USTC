/********************************************************************************
 * Description  :
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-04-19 22:54:48
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-04-20 16:05:20
 * FilePath     : \\project\\Program22\\Program22.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

#define f(x, y, z) (0.09 * (y) * (1 - (y) / 20) - 0.45 * (y) * (z))
#define g(x, y, z) (0.06 * (z) * (1 - (z) / 15) - 0.001 * (y) * (z))
#define y_0 1.6
#define z_0 1.2

int main()
{
    int n;
    double y_1, y_t, y_2, z_1, z_t, z_2;
    printf("\nInput n value:  ");
    scanf("%d", &n);
    double h;
    printf("\nInput h value:  ");
    scanf("%lf", &h);

    y_1 = y_0;
    z_1 = z_0;
    for (int k = 1; k <= n; k++)
    {
        printf("\n(y_%d, z_%d) = (%lf, %lf)\n", k, k, y_1, z_1);
        y_t = y_1 + h * f(0, y_1, z_1);
        z_t = z_1 + h * g(0, y_1, z_1);
        y_2 = y_1 + h / 2 * (f(0, y_1, z_1) + f(0, y_t, z_t));
        z_2 = z_1 + h / 2 * (g(0, y_1, z_1) + g(0, y_t, z_t));
        y_1 = y_2;
        z_1 = z_2;
    }
    return 0;
}