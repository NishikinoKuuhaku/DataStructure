// 冒泡排序
a[j] > a[j+1]

if (a[j] < a[j+1])
{
    int tmp = a[j];
    a[j] = a[j+1];
    a[j + 1] = tmp;
}

for (j = 0; j <= n - 2; j++)
{
    if (a[j] < a[j+1])
    {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j + 1] = tmp;
    }
}

for (i = 1; i <= n - 1; i++)
{
    for (j = 0; j <= n - 1 - i; j++)
    {
        if (a[j] < a[j+1])
        {
            int tmp = a[j];
            a[j] = a[j+1];
            a[j + 1] = tmp;
        }
    }
}

// 选择排序
int max = 0; // 当前你知道的最高的
for (i = 1; i < n; i++)
{
    if (a[i] > a[max])
    {
        max = i;
    }
}
int tmp = a[0];
a[0] = a[max];
a[max] = tmp;

for (j = 0; j < n - 1; j++)
{
    int max = j;
    for (i = j + 1; i < n; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    int tmp = a[j];
    a[j] = a[max];
    a[max] = tmp;
}

// 时间复杂度 - O
O 正比于程序运行的时间

if (/* condition */)
{
    /* code */
}
- O(1)

for (i = 0; i < n; i++)
{
    if (/* condition */)
    {
        /* code */
    }
}
- O(n)

for (i = 0; i < n; i++)
{
    for (j = 0; j < n; j++)
    {
        if (/* condition */)
        {
            /* code */
        }
    }
}
- O(n^2)

猴子排序（不重复）
- O(n!*(n-1)) ~ O(n!)
(阶乘：n! = 1 * 2 * 3 * ··· * n, 0! = 1)
(0!+0!+0!+0!)! == 24

猴子排序（重复）
- O(n^n*(n-1)) ~ O(n^n)

选择排序
- O(n + (n - 1) + (n - 2) + ··· + 1) = (1 + n) * n / 2 = n^2 / 2 + n / 2 = O(n^2)

// 空间复杂度
你用了多少内存