#include <stdio.h>
int main()
{
    int avg[1000] = {0}, i, j, k;
    double sum = 0;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &avg[i]);
    }
    for (i = 0; i < k; i++)
    {
        sum += avg[i];
    }
    for (i = 0; i < k - 1; i++)
    {
        int maxindex = i;
        for (j = i; j < k; j++)
        {
            if (avg[j] > avg[maxindex])
            {
                maxindex = j;
            }
        }
        int temp = avg[i];
        avg[i] = avg[maxindex];
        avg[maxindex] = temp;
    }
    float d;
    d = sum - (int)sum;
    if (d >= 5)
    {
        printf("%.1f", sum / k + 1);
    }
    else
    {
        printf("%.1f", sum / k);
    }
    printf("%d\n", avg[k / 2]);
    return 0;
}