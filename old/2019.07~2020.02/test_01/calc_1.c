#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int num[1000] = {0};                     // 储存数字
    char act[1000] = {0}, input[1000] = {0}; // 储存操作符和输入的表达式
    fgets(input, 1000, stdin);               // 输入函数（不唯一）

    int i = 0, p = 0, numTmp = 0;
    while (input[i] != '=')
    {
        if (input[i] >= '0' && input[i] <= '9') // 字符串转换为数字
        {
            numTmp *= 10;
            numTmp += input[i] - '0';
        }
        else if (input[i] != ' ') // 将数字和操作符写入数组并重置状态
        {
            num[p] = numTmp;
            act[p] = input[i];
            numTmp = 0;
            p++;
        }
        i++;
    }
    num[p] = numTmp; // 最后一个数字注意要存入数组

    int result = num[0]; // 计算表达式
    for (i = 0; i < p; i++)
    {
        if (act[i] == '+')
        {
            result += num[i + 1];
        }
        else
        {
            result -= num[i + 1];
        }
    }
    printf("%d", result);

    // getchar();
    // getchar();
    return 0;
}
