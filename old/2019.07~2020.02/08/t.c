#include <stdio.h>

void f(int m, int *a)
{
    a[1] = m;
}

int main(int argc, char const *argv[])
{
    int m = 3, n = 1;
    int a[] = {1, 2, 3};

    f(m, a);

    return 0;
}
