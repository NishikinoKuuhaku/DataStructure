#include <stdio.h>
#include <string.h>

// s1 > s2: return +
// s1 == s2: return 0
// s1 < s2: return -
int compare(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    int i;

    if (l1 != l2)
    {
        return l1 - l2;
    }
    else
    {
        for (i = 0; i < l1; i++)
        {
            if (s1[i] != s2[i])
            {
                return s1[i] - s2[i];
            }
        }
    }
    return 0;
}

void pointerSort(int size, char **arr)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            // 比较 arr[j] 和 arr[j+1] 的大小
            int res = compare(arr[j], arr[j + 1]);
            if (res > 0)
            {
                char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char s1[] = "114";
    char s2[] = "514";
    char s3[] = "24";
    char *arr[3] = {s1, s2, s3};

    pointerSort(3, arr);

    return 0;
}
