
/*
 * Author: Аветисян Арташес Робертович
 * Лабораторная работа №3, вариант 4
 * (xln3)^0 / 0!  + (xln3)^1 / 1! + (xln3)^2 / 2! +... (xln3)^n / n!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int factorial(int n);
double sum (double x, double eps);

int main(int argc, char** argv)
{

    double x;

    for (x = 0.1; x <= 1; x += 0.1)
    {

        printf("x = %lf; sum = %lf; function_3^x = %lf\n", x, sum(x, 0.0001), pow(3, x));
    }

    return (EXIT_SUCCESS);
}

double sum(double x, double eps)
{
    double overallSumm = 0.;
    double currentIterationResult = 1;

    for (int n = 1; fabs(currentIterationResult) > eps; n++)
    {
        overallSumm += currentIterationResult;
        currentIterationResult *= x* log(3) / n;
    }
    return overallSumm;
}



long int factorial(int n)
{

    if (n > 1){

        return n * factorial(n-1);
    } else {

        return 1;
    }
}