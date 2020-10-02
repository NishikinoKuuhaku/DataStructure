#include <stdio.h>
int main()
{
    int i, j;
    int n;
    int m;
    int a[1000] = {};
    int array[1000] = {};
    scanf("%d %d", &n, &m);
    for (i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    for (i = 0; m != -1 && i <= n; i++)
    {
        if (a[i] < 10)
        {
            array[i] = a[i];
        }
        if (a[i] >= 10)
        {
            int temp = a[i] / 10;
            int temp_l = a[i] % 10;
            array[i] = temp;
            array[i + 1] = temp_l;
            i++;
        }
    }
}