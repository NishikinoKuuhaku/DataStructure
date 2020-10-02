#include <stdio.h>
int main()
{
    int h, f, i, a, b;
    while (scanf("%d %d", &h, &f) != EOF)
    {
        for (i = 0; i <= h; i++)
        {
            a = i;
            b = h - i;
            if (a * 2 + b * 4 == f)
            {
                break;
            }
            if (i <= h)
            {
                printf("%d %d\n", a, b);
            }
            else
            {
                printf("no solution\n");
            }
        }
        return 0;
    }