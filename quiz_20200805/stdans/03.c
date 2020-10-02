#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addStrings(char *num1, char *num2)
{
    int l1 = strlen(num1), l2 = strlen(num2);
    int maxlen = (l1 > l2) ? l1 : l2;

    // 补零
    char *n1_full = (char *)calloc(maxlen + 2, sizeof(char));
    char *n2_full = (char *)calloc(maxlen + 2, sizeof(char));
    for (int i = 0; i < maxlen + 2; i++)
    {
        n1_full[i] = (i >= maxlen + 1 - l1) ? num1[i - 1 - maxlen + l1] : '0';
        n2_full[i] = (i >= maxlen + 1 - l2) ? num2[i - 1 - maxlen + l2] : '0';
    }

    // 计算
    int prev = 0;
    char *result_full = (char *)calloc(maxlen + 2, sizeof(char));
    for (int i = maxlen; i >= 0; i--)
    {
        int curr = prev + (n1_full[i] - '0') + (n2_full[i] - '0');
        result_full[i] = curr % 10 + '0';
        prev = curr / 10;
    }

    // 加上尾部的 '\0' & 删除头部的零
    result_full[maxlen + 1] = '\0';
    while (result_full[0] == '0')
    {
        result_full++;
    }

    // 清除临时变量
    free(n1_full);
    free(n2_full);

    return result_full;
}

int main(int argc, char const *argv[])
{
    char num1[] = "1239", num2[] = "99999956";

    printf("%s", addStrings(num1, num2)); // print "579"

    return 0;
}
