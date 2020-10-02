#include <stdio.h>

int main(int argc, char const *argv[])
{
    int oddNum = 0, evenNum = 0; // 奇数和偶数的个数
    int n, i, j;
    long long odd[1000], even[1000]; // 奇数和偶数的数组
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        long long input;
        scanf("%lld", &input);
        if (input > 0)
        {
            if (input % 2 == 1) // 区分奇偶
            {
                odd[oddNum] = input;
                oddNum++;
            }
            else
            {
                even[evenNum] = input;
                evenNum++;
            }
        }
    }

    for (i = 0; i < oddNum; i++) // 奇数排序
    {
        for (j = 0; j < oddNum - 1 - i; j++)
        {
            if (odd[j] > odd[j + 1])
            {
                int tmp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < evenNum; i++) // 偶数排序
    {
        for (j = 0; j < evenNum - 1 - i; j++)
        {
            if (even[j] < even[j + 1])
            {
                int tmp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < oddNum; i++) // 分别输出
    {
        printf("%lld ", odd[i]);
    }
    for (i = 0; i < evenNum; i++)
    {
        printf("%lld ", even[i]);
    }

    getchar();
    getchar();
    return 0;
}
