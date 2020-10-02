#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, i, j;
    int num[1000];
    long long sum = 0;
    double avg;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i]; // 计算和
    }

    avg = (double)sum / (double)n; // 计算平均数并输出
    printf("%.1lf\n", avg);

    for (i = 0; i < n; i++) // 排序（此处用的是冒泡排序）
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
    int p;
    p = (n == n / 2 * 2) ? n / 2 : n / 2 + 1; // 寻找中位数的位置
    p = (n + 1) / 2;                          // 这种方法也可以，是一个意思
    printf("%d", num[p - 1]);
    double test = 0.05;
    getchar();
    getchar();
    return 0;
}
