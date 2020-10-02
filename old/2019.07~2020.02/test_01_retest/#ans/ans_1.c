#include <stdio.h>
int main()
{
    int i, j;
    int k;
    int ap = 0, np = 0;
    int temp, min;
    int a[1000];
    int num[1000];
    int num_l[1000] = {0};
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < k; i++)
    {
        if (a[i] % 2 != 0 && a[i] != 0)
        {
            num[ap] = a[i];
            ap++;
        }
        if (a[i] % 2 == 0 && a[i] != 0)
        {
            num_l[np] = a[i];
            np++;
        }
    }
    for (i = 0; i < ap; i++)
    {
        for (j = 0; j < ap; j++)
        {
            if (num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j <= np; j++)
        {
            if (num_l[j] < num_l[j + 1])
            {
                temp = num_l[j];
                num_l[j] = num_l[j + 1];
                num_l[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < ap; i++)
    {
        a[i] = num[i];
    }
    for (j = i, min = 0; j < k; j++, min++)
    {
        a[j] = num_l[min];
    }
    for (i = 0; i < k; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}