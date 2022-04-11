/********************************************************************************
 * Description  : SNM_Program2
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-03-17 10:16:47
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-03-17 22:16:11
 * FilePath     : \\2022Spr\\SolutionforNumericalMethods\\project\\Program2.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#include <stdio.h>
#define MAX_N 20

typedef struct stPoint
{
    double x;
    double y;
} Point;

int main()
{
    int n;
    int i, j;
    Point points[MAX_N];
    double x, tmp, lagrange = 0;

    printf("\nInput n value:  ");
    scanf("%d", &n);

    if (n > MAX_N)
    {
        printf("The input n is larger than MAX_N, please redefine the MAX_N.\n");
        return 1;
    }
    if (n <= 0)
    {
        printf("Please input a number between 1 and %d.\n", MAX_N);
        return 1;
    }

    //输入被插值点(x_i,y_i)
    printf("Now input the (x_i, y_i), i = 0, ..., %d:\n", n);
    for (i = 0; i <= n; i++)
        scanf("%lf%lf", &points[i].x, &points[i].y);

    //输入计算拉格朗日插值多项式的x值
    printf("\nNow input the x value:  ");
    scanf("%lf", &x);

    for (i = 0; i <= n; i++)
    {
        tmp = 1;
        for (j = 0; j <= n; j++)
        {
            if (j == i)
                continue;
            tmp = tmp * (x - points[j].x) / (points[i].x - points[j].x);
        }
        lagrange = lagrange + tmp * points[i].y;
    }
    printf("\nlagrange(%lf)=%lf\n", x, lagrange);
    return 0;
}