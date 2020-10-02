#include <stdio.h>
int main()
{
    int i, j;
    int m, n;
    int x = 0;
    int a[1000] = {}, b[1000] = {}, c[1000] = {};
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    int temp = m + n;
    if (temp)
    {
        for (i = 0; i < temp - 1; i++)
        {
            for (j = 0; j < temp - 1 - i; j++)
            {
                if (a[i] == b[j])
                {
                    c[j] = a[i];
                    temp--;
                    x++;
                }
            }
        }
    }
    if (x = 0)
    {
        printf("null");
    }
    temp = m + n;
    for (i = 0; i < temp - 1; i++)
    {
        for (j = 0; j < temp - 1 - i; j++)
        {
            if (c[j] > c[j + 1])
            {
                int temp_l = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp_l;
            }
        }
    }
    for (i = 0; i < temp; i++)
    {
        if (c[i] != 0)
        {
            printf("%d ", c[i]);
        }
        else
        {
            continue;
        }
    }
}