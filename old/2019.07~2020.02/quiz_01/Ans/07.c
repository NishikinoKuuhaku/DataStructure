#include<stdio.h>
int main()
{
    int i,j;
    char a[1000],b[1000];
    gets(a);
    gets(b);
    int ret;
    int temp;
    int len = strlen(a);
    int len_l = strlen(b);
    ret = len + len_l;
    for ( i = 0; i < ret - 1; i++)
    {
        for ( j = 0; j < ret - i - 1; j++)
        {
            if (b[i]==a[j])
            {
                temp++;
            }
        }
    }
    if (temp==0)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
}