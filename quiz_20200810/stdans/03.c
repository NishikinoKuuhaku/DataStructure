#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

char *convert(char *s, int n0, int n1)
{
    // 先按 n0 转换为 int
    int val = 0;
    while (*s != '\0')
    {
        val *= n0;
        val += *s - '0';
        s++;
    }
    // 用模运算得出 n1 表示的字符序列（反序）
    char backwards[50] = {0};
    int rlen = 0;
    while (val > 0)
    {
        backwards[rlen] = table[val % n1];
        val /= n1;
        rlen++;
    }
    // 将反序的字符序列转换为顺序的字符串
    char *rstr = (char *)malloc(sizeof(char) * (rlen + 1));
    for (int i = 0; i < rlen; i++)
    {
        rstr[i] = backwards[rlen - 1 - i];
    }
    rstr[rlen] = '\0';

    return rstr;
}

int main(int argc, char const *argv[])
{
    char s[] = "2333";
    int n0 = 8, n1 = 10;

    printf("%s", convert(s, n0, n1)); // print "101111"

    return 0;
}
