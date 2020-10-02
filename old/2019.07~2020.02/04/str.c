/*
（英文）字符串(string): 数组
char str[100];

A - 01010011
B - 01010100
C - 01010101

ASCII
字符 - 编码序号
1    -   49
2    -   50
3    -   51

字符串：由字符编码序号组成的数组
char   -128 ~ +127
ASCII     0 ~ +127

字符串：char 数组
char str[100];
 */

"a" 'a'

'a' // 字符
"a" // 长度为 1 的字符串

str[100] = "123"
{49,50,51,0,···,···}
str[100] = '123'
{49,50,51,···,···}
// ASCII 码的零号： \0
// 字符串的结尾必定为 \0

#include <string.h>
#include <stdio.h>

strlen(str) // 求字符串的长度 (返回值为正整数 int)
{
    char str[100] = "abcdefg";
    strlen(str) == 7;
    sizeof(str) == 100;
    int num[10];
    sizeof(num) == 4 * 10 = 40;
}

strlen(char str[])
{
    int i = 0;
    for (i = 0; str[i] != 0; i++)
    {
        continue;
    }
    return i;
}

bit/b   -->  0/1
1byte/1B  =  8bit

strcpy(dest,src)
{
    char str1[10] = "12345", str2[10] = "234";
    printf("%s", str1); // 12345
    strcpy(str1, str2);
    printf("%s", str1); // 234
}

strcat(dest,src)
{
    char str1[10] = "12345", str2[10] = "abc";
    printf("%s", str1); // 12345
    strcat(str1, str2);
    printf("%s", str1); // 12345abc
}

strcmp(str1, str2)
{
    char str1[10] = "12345", str2[10] = "abc";
    strcmp(str1, str2) < 0

    char str1[10] = "12345", str2[10] = "12345";
    strcmp(str1, str2) == 0

    char str1[10] = "12345", str2[10] = "abc";
    strcmp(str2, str1) > 0

    char str1[10] = "12345", str2[10] = "123 \0";
    srtcmp(str1, str2) > 0
}

strcmp_ori(char str1[], char str2[])
{
    int i;
    for (i = 0; str1[i] != 0 && str2[i] != 0; i++)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }
    // if (str1[i] == str2[i])
    // {
    //     return 0;
    // }
    // else if (str1[i]==0)
    // {
    //     return 0 - str2[i];
    // }
    // else // str2[i] == 0
    // {
    //     return str1[i] - 0;
    // }
    return str1[i] - str2[i];
}

char num[10] = "12345"; ------------ > int _num = 12345;

int _num = 0;
for (i = 0; i < strlen(num); i++)
{
    _num *= 10;
    _num += num[i] - '0';
}


if (str[i] == 'a')
{
    /* 推荐 */
}

if (str[i] == 65)
{
    /* code */
}
