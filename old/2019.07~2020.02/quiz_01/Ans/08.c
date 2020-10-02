#include <stdio.h>
#include <string.h>
int main()
{
    int i, j;
    int num[1000] = {};
    char str[1000] = {};
    int len;
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        num[i]++;
    }
    for (i = 0; i < len - 1; i++)
    {
        for (j = i; j < len - 1; j++)
        {
            if (str[i] == str[j + 1])
            {
                num[i]++;
                str[j + 1] = ' ';
                num[j + 1] = 0;
            }
        }
    }
    for (i = 0; i < len - 1; i++)
    {
        if (str[i] != ' ')
        {
            printf("%c %d\n", str[i], num[i]);
        }
        else
        {
            continue;
        }
    }
    getchar();
    getchar();
    return 0;
}