/********************************************************************************
 * Description  :
 * Version      : 1.0
 * Author       : YingKang Zhong
 * Date         : 2022-05-29 22:31:12
 * LastEditors  : YingKang Zhong
 * LastEditTime : 2022-05-29 23:06:54
 * FilePath     : \\FinalProject_part2\\FinalProject_part2.c
 * Copyright (C) 2022 YingKang Zhong. All rights reserved.
 ********************************************************************************/
#include <stdio.h>
#include <math.h>

#define epsilon 1 / pow(10, 10)
#define MAX_N 300
#define PI acos(-1)
#define f(x) PI *PI *sin(PI *(x))
#define u_e(x) sin(PI *(x))

double xj1[MAX_N];
double xj2[MAX_N];
double xg1[MAX_N];
double xg2[MAX_N];

int main()
{
    int i, j;
    int flagj = 0, flagg = 0;
    int n = 10;
    double h = 1.0;
    double deltaj = 1.0;
    double deltag = 1.0;
    double sumj = 0.0;
    double sumg = 0.0;
    int timesj = 0;
    int timesg = 0;
    for (n = 10; n <= 160; n = n * 2)
    {
        printf("\nn = %d:\n",n);

        h = 1.0 / n;

        for (i = 0; i <= n; i++)
        {
            xj1[i] = 0.0;
            xg1[i] = 0.0;
            xg2[i] = 0.0;
        }

        flagj = 0;
        flagg = 0;
        timesj = 0;
        timesg = 0;
        while (flagj + flagg != 2)
        {
            timesj++;
            timesg++;
            for (i = 1; i < n; i++) // x[0]&x[n]在迭代过程中未改变，始终为0
            {
                xj2[i] = 0.5 * xj1[i - 1] + 0.5 * xj1[i + 1] + 0.5 * h * h * f(i * h);
                xg2[i] = 0.5 * xg2[i - 1] + 0.5 * xg1[i + 1] + 0.5 * h * h * f(i * h);
            }

            deltaj = fabs(xj2[1] - xj1[1]);
            deltag = fabs(xg2[1] - xg1[1]);
            for (i = 2; i < n; i++)
            {
                deltaj = (deltaj > fabs(xj2[i] - xj1[i])) ? deltaj : fabs(xj2[i] - xj1[i]);
                deltag = (deltag > fabs(xg2[i] - xg1[i])) ? deltag : fabs(xg2[i] - xg1[i]);
            }
            if (deltaj < epsilon)
            {
                if (flagj == 0)
                {
                    sumj = pow(xj2[1] - u_e(h), 2);
                    for (i = 2; i < n; i++)
                        sumj += pow(xj2[i] - u_e(i * h), 2);
                    sumj = sqrt(sumj);
                    printf("  In %5d J: %.11llf\n",timesj,sumj);
                }
                flagj = 1;
            }
            if (deltag < epsilon)
            {
                if (flagg == 0)
                {
                    sumg = pow(xg2[1] - u_e(h), 2);
                    for (i = 2; i < n; i++)
                        sumg += pow(xg2[i] - u_e(i * h), 2);
                    sumg = sqrt(sumg);
                    printf("  In %5d G: %.11llf\n",timesg,sumg);
                }
                flagg = 1;
            }

            for (i = 1; i < n; i++)
            {
                xj1[i] = xj2[i];
                xg1[i] = xg2[i];
            }
        }
    }
    return 0;
}