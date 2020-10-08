// 修改此处，让结构可以存储字符串
#define BLL_DATA_TYPE void*

#include "BLLObject.c"
#include <assert.h>

#define MAX_STR_LEN 1000    // 字符串的最大长度
#define MAX_UNDO_NUM 5      // 最多保存的撤销次数

// 这是你需要修改的字符串
char s[MAX_STR_LEN] = "";
// 如果需要增加全局变量，请在此处添加
/* Code Here */

void stringEdit(int mode, int pos, void *content)
{
    switch (mode)
    {
    // 插入（可以复用以前的代码）
    case 1:
        /* Code Here */
        break;
    // 删除（可以复用以前的代码）
    case 2:
        /* Code Here */
        break;
    // 撤销
    case 3:
        /* Code Here */
        break;
    // 重做
    case 4:
        /* Code Here */
        break;
    default:
        printf("error mode code: %d", mode);
        break;
    }
}

int main(int argc, char const *argv[])
{
    // 如果你需要初始化全局变量，请在此处初始化
    /* Code Here */

    int pos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *strings[] = {"abcd", "0000", "xyz", "1234", "++--"};

    stringEdit(1, 0, strings[0]);
    printf("\"%s\"\n", s); // "abcd"
    stringEdit(1, 4, strings[1]);
    printf("\"%s\"\n", s); // "abcd0000"
    stringEdit(1, 6, strings[4]);
    printf("\"%s\"\n", s); // "abcd00++--00"
    stringEdit(2, 7, pos + 2);
    printf("\"%s\"\n", s); // "abcd00+-00"
    stringEdit(1, 0, strings[3]);
    printf("\"%s\"\n", s); // "1234abcd00+-00"
    stringEdit(2, 2, pos + 4);
    printf("\"%s\"\n", s); // "12cd00+-00"
    stringEdit(3, 0, 0);
    printf("\"%s\"\n", s); // "1234abcd00+-00"
    stringEdit(3, 0, 0);
    printf("\"%s\"\n", s); // "abcd00+-00"
    stringEdit(3, 0, 0);
    printf("\"%s\"\n", s); // "abcd00++--00"
    stringEdit(3, 0, 0);
    printf("\"%s\"\n", s); // "abcd0000"
    stringEdit(3, 0, 0);
    printf("\"%s\"\n", s); // "abcd"
    stringEdit(3, 0, 0);   // unable to perform undo
    printf("\"%s\"\n", s); // "abcd"
    stringEdit(4, 0, 0);
    printf("\"%s\"\n", s); // "abcd0000"
    stringEdit(4, 0, 0);
    printf("\"%s\"\n", s); // "abcd00++--00"
    stringEdit(1, 0, strings[2]);
    printf("\"%s\"\n", s); // "xyzabcd00++--00"
    stringEdit(4, 0, 0);   // unable to perform redo
    printf("\"%s\"\n", s); // "xyzabcd00++--00"
    return 0;
}