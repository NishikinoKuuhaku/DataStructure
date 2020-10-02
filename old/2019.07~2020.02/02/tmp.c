void bubbleSort(int a[], int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i; j++)
        {
            // j = n - 1
            if (a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}




1 2 3 4 5



// 3 4 1 5 2

3 4 1 5 2
3 1 4 5 2
3 1 4 5 2
3 1 4 2 5

1 3 4 2   5
1 3 4 2   5
1 3 2 4   5

1 3 2   4 5
1 2 3   4 5

1 2   3 4 5

  1 2 3 4 5

第 i 次:  1 ~ (5 - i + 1) 位数字间比较

if(a[j]>a[j+1])

n 个数字，第 i 次： 1 ~ (n - i + 1) 个数字间比较