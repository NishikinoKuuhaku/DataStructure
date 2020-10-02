#include <stdio.h>

void complex(int a1, int a2, int b1, int b2, char act, double *dest)
{
    /* Code Here */
}

int main(int argc, char const *argv[])
{
    int a1 = 1, a2 = 2, b1 = 3, b2 = 4;
    char act = '+';
    double result[2] = {0};

    complex(a1, a2, a3, a4, act, result);

    printf("%lf %lf", result[0], result[1]);
    return 0;
}
