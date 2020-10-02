#include <stdio.h>
main()
{
    int x;
    scanf("%d", &x);
    int i, j, k, a, b, m, num[100];
    for (i = 0; i < x; i++)
    {
        scanf("%d", &num[i]);
    }
    for (j = 0; j < x; j++)
    {
        for (k = j + 1; k < x; k++)
        {
            if (num[k] > num[j])
            {
                a = num[j];
                num[j] = num[k];
                num[k] = a;
            }
        }
    }
    scanf("%d", &m);
    printf("%d", num[m - 1]);
}
