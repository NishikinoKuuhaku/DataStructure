#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num[100], i, j, max, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        max = 0;
        for (j = i; j < n - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                max = j;
            }
        }
        int temp = num[max];
        num[max] = num[i];
        num[i] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }

    getchar();
    getchar();
    return 0;
}
