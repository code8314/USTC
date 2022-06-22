/********************************************************************************
 * Description  :
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-05-30 21:08:37
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-05-30 23:35:39
 * FilePath     : \\FinalProject_part6\\FinalProject_part6.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#include <stdio.h>
#include <math.h>

#define epsilon 1 / pow(10, 8)
#define MAX_N 300
#define PI acos(-1)
#define f(x) (PI * PI * sin(PI * (x)) + pow(sin(PI * (x)), 3))
#define u_e(x) sin(PI *(x))

double u[MAX_N];
double v[MAX_N];
double y[MAX_N];
double x[MAX_N];
double delta_x[MAX_N];
double f[MAX_N];

int main()
{
    int i, j;
    double delta = 1.0;
    double h = 1.0;
    double sum = 0.0;
    int n;
    int count;

    for (n = 10; n <= 160; n = n * 2)
    {
        printf("\nn = %d:\n", n);

        count = 0;
        h = 1.0 / n;
        sum = 0.0;

        for (i = 1; i < n; i++)
        {
            x[i] = 1.0;
            delta_x[i] = 1.0;
        }

        x[0] = 1.0;
        x[n] = 0.0;
        delta = 1.0;
        while (delta > epsilon)
        {
            /*
            for (i = 1; i < n; i++) // x[0]&x[n]在迭代过程中未改变，始终为0
            {
                f[i] = pow(x[i], 3) + n * n * (2 * x[i] - x[i - 1] - x[i + 1]) - f(i * h);
            }
            u[0] = 0.0;
            v[0] = 0.0;
            y[0] = 0.0;
            for (i = 1; i < n; i++)
            {
                u[i] = 3 * x[i] * x[i] + 2 * n * n * v[i - 1];
                v[i] = -n * n / u[i];
                y[i] = (-f[i] + n * n * y[i - 1]) / u[i];
            }

            delta_x[n - 1] = y[n - 1];
            for (i = n - 2; i >= 1; i--)
            {
                delta_x[i] = y[i] - v[i] * delta_x[i + 1];
            }

            delta = 0.0;
            for (i = 1; i < n; i++)
            {
                x[i] += delta_x[i];
                delta = (fabs(delta_x[i]) > delta) ? fabs(delta_x[i]) : delta;
            }

            count++;
            */
            f[1] = pow(x[1], 3) + n * n * (2 * x[1] - x[2]) - f(h);
            for (i = 2; i < n - 1; i++)
            {
                f[i] = pow(x[i], 3) + n * n * (2 * x[i] - x[i - 1] - x[i + 1]) - f(i * h);
            }
            f[n - 1] = pow(x[n - 1], 3) + n * n * (2 * x[n - 1] - x[n - 2]) - f((n - 1) * h);
            // 重设方程组右值

            u[1] = 3 * x[1] * x[1] + 2 * n * n;
            v[1] = -n * n / u[1];
            y[1] = -f[1] / u[1];
            for (i = 2; i < n; i++)
            {
                u[i] = 3 * x[i] * x[i] + 2 * n * n + n * n * v[i - 1];
                v[i] = -n * n / u[i];
                y[i] = (-f[i] + n * n * y[i - 1]) / u[i];
            }
            delta_x[n - 1] = y[n - 1];
            for (i = n - 2; i >= 1; i--)
                delta_x[i] = y[i] - v[i] * delta_x[i + 1];

            // 追赶法解方程 (三对角方程)

            for (i = 1; i < n; i++)
                x[i] += delta_x[i];

            count++;
            delta = 0.0;
            for (i = 1; i < n; i++)
            {
                delta = (fabs(delta_x[i]) > delta) ? fabs(delta_x[i]) : delta;
            }
            printf("times = %2d\n", count);
            sum = 0.0;
            for (i = 1; i < n; i++)
            {
                // printf("x[%3d] = %.9llf\n", i, x[i]);
                sum += pow((x[i] - u_e(i * h)), 2);
            }
            sum = sqrt(sum);
            printf("e_h = %.9llf\n", sum);
        }
        printf("times = %2d\n", count);
        sum = 0.0;
        for (i = 1; i < n; i++)
        {
            // printf("x[%3d] = %.9llf\n", i, x[i]);
            sum += pow((x[i] - u_e(i * h)), 2);
        }
        sum = sqrt(sum);
        printf("e_h = %.9llf\n", sum);
    }
    return 0;
}