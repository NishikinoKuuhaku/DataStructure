#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char str[1000];
    scanf("%s", str);
    int i, num[1000], len = strlen(str);
    int np = 0, ntemp = 0, flg = 0;
    for (i = 0; i < len;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            ntemp *= 10;
            ntemp += str[i] - '0';
            flg = 1;
        }
        else if(flg==1)
        {
            num[np] = ntemp;
            np++;
            ntemp = 0;
            flg = 0;
        }
    }

    if (np != 0)
    {
        for (i = 0; i < np; i++)
        {
            printf("%d ", num[i]%2019);
        }
    }
    else
    {
        printf("-1");
    }

    getchar();
    getchar();
    return 0;
}
