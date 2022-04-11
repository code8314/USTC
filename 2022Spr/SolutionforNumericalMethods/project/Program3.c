/********************************************************************************
 * Description  : SNM_Program3
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-03-17 10:16:47
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-03-17 22:17:24
 * FilePath     : 2022Spr\\SolutionforNumericalMethods\\project\\Program3.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#include <stdio.h>
#define MAX_N 20
typedef struct tagPOINT
{
    /* data */
    double x;
    double y;
} POINT;
int main()
{
    int n;
    int i, j;
    POINT points[MAX_N + 1];
    double diff[MAX_N + 1];
    double x, tmp, newton = 0;

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

    //输入计算Newton插值多项式的x值
    printf("Now input the x value:  ");
    scanf("%lf", &x);

    for (i = 0; i <= n; i++)
        diff[i] = points[i].y;
    for (i = 0; i < n; i++)
        for (j = n; j > i; j--)
            diff[j] = (diff[j] - diff[j - 1]) / (points[j].x - points[j - 1 - i].x);
    tmp = 1;
    newton = diff[0];
    for (i = 0; i < n; i++)
    {
        tmp = tmp * (x - points[i].x);
        newton = newton + tmp * diff[i + 1];
    }
    printf("newton(%f) = %f\n", x, newton);
    return 0;
}
