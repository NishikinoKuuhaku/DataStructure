#include <stdio.h>

int posOfFile(int *history, int lookup)
{
}

int main(int argc, char const *argv[])
{
    int history[] = {1, 2, 3, 4, 5, -2, 6, 7, 8, 9, -3, 10, 11, -1, -2, 0};
    int lookup = 1;

    printf("%d", posOfFile(history, lookup));

    return 0;
}
