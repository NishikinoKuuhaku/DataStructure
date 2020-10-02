#include <stdio.h>

int calc(int n, int *w, int *a)
{
    /* Code Here */
}

int main(int argc, char const *argv[])
{
    int w[4] = {1, 0, 2, 3};
    int a[4] = {-1, 2, 100, 3};

    int r = calc(4, w, a);

    printf("%d", r);
    return 0;
}
