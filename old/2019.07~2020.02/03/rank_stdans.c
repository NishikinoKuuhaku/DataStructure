#include <stdio.h>

int main(int argc, char const *argv[])
{
    int grades[100], n, m;
    int i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &grades[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (grades[j - 1] < grades[j])
            {
                int tmp = grades[j - 1];
                grades[j - 1] = grades[j];
                grades[j] = tmp;
            }
        }
    }

    // case 1
    scanf("%d", &m);
    printf("%d", grades[m - 1]);

    // case 2
    // scanf("%d", &m);
    // while (m != 0)
    // {
    //     printf("%d", grades[m - 1]);
    //     scanf("%d", &m);
    // }

    getchar();
    getchar();

    return 0;
}
