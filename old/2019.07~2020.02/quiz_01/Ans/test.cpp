#include <stdio.h>
int main()
{
    int i, j;
    int m = 6, n = 4;
    int temp = m + n;
    int x = 0;
    int a[1000] = {1, 6, 2, 1, 5, 3}, b[1000] = {3, 2, 5, 4}, c[1000] = {};
    for (i = 0; i < m; i++)
    {
        c[i] = a[i];
    }
    i = 0;
    for (j = m; j < temp; j++)
    {
        c[j] = b[i];
        i++;
    }
    for (i = 0; i < temp - 1; i++)
    {
        int ptr = i;
        for (j = i + 1; j < temp; j++)
        {
            if (c[j] == c[ptr])
            {
                c[ptr] = 0;
                x++;
            }
        }
    }
    for (i = 0; i < temp - 1; i++)
    {
        for (j = 0; j < temp - 1 - i; j++)
        {
            if (c[j] < c[j + 1])
            {
                int tmp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = tmp;
            }
        }
    }

    for (i = x - 1; i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    return 0;
}
