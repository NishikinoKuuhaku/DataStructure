// 输出的类型名称 函数名(输入)
// {

// }

// 输出：
// char int double float
// void // 不输出

// 输入：
// 变量类型 变量名, 变量类型 变量名
#include <stdio.h>

int ten2ten(int n, int m)
{
    int times = 0; // m 出现的次数
    for (size_t i = 1; i <= n; i++)
    {
        int _i = i;
        while (_i != 0)
        {
            if (_i % 10 == m)
            {
                times++;
            }
            _i = _i / 10;
        }
    }
    return times;
}

int main(int argc, char const *argv[])
{
    printf("%d", ten2ten(20, 2));

    return 0;
}
