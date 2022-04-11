/********************************************************************************
 * Description  : SNM_Program8
 * Version      : 3.0
 * Author       : YingKang Zhong
 * Date         : 2022-03-29 11:44:11
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-04-08 09:53:10
 * FilePath     : \\SolutionforNumericalMethods\\project\\Program8\\Program8.cpp
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

#define f(x) (log(x))
#define m 100

int main()
{
    double a, b, h, epsilon;
    int n = 2 * m;
    int i;
    double S_n, H_n_half, H_n, S1, S2; //迭代计算中S1和S2分别表示Sn和S2n

    printf("\nInput a & b value:  ");
    scanf("%lf%lf", &a, &b);
    printf("\nInput epsilon value:  ");
    scanf("%lf", &epsilon);

    h = (b - a) / n;
    S_n = f(a) + f(b);
    for (i = 0; i < m; i++)
        S_n += 4 * f(a + h * (2 * i + 1));
    for (i = 1; i < m; i++)
        S_n += 2 * f(a + h * 2 * i);

    S_n *= h / 3;
    S2 = S_n;
    S1 = S2 + 100;

    do
    {
        /* code */
        S1 = S2;
        for (i = 0, H_n_half = 0; i < n / 2; i++)
            H_n_half += f(a + h * 2 * i + h);
        H_n_half *= h * 2;
        for (i = 0, H_n = 0; i < n; i++)
            H_n += f(a + h * i + h / 2);
        H_n *= h;
        /*for (i = 0, H_2n = 0; i < 2 * n; i++)
            H_2n += f(a + h / 2 * i + h / 4);
        H_2n *= h / 2;*/
        S2 = S1 / 2 + (4 * H_n - H_n_half) / 6;
        h = h / 2;
        n = n * 2;
    } while (/* condition */ fabs(S1 - S2) > epsilon);

    printf("\nT=%lf\n\n", S2);
    return 0;
}