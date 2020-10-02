#include <stdio.h>
#include <stdlib.h>

struct student
{
    int score;
    int chinese, math, english;
    char name[20];
};

typedef struct student stu;

// 如果返回正数：a的成绩比b好
// 如果返回 0 ：a的成绩和b一样好
// 如果返回负数：b的成绩比a好
// int compare(stu a, stu b)
// {
//     if (a.score != b.score)
//     {
//         return a.score - b.score;
//     }
//     else if (a.chinese != b.chinese)
//     {
//         return a.chinese - b.chinese;
//     }
//     else if (a.math != b.math)
//     {
//         return a.math - b.math;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int cmp_int(const void *p1, const void *p2)
// {
//     int *intp1, *intp2;
//     intp1 = (int *)p1;
//     intp2 = (int *)p2;
//     return *intp2 - *intp1;
// }

int cmp_stu(const void *p1, const void *p2)
{
    stu a, b;
    a = *((stu *)p2);
    b = *((stu *)p1);
    if (a.score != b.score)
    {
        return a.score - b.score;
    }
    else if (a.chinese != b.chinese)
    {
        return a.chinese - b.chinese;
    }
    else if (a.math != b.math)
    {
        return a.math - b.math;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    stu students[100];

    // 输入
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, students[i].math, students[i].chinese, students[i].english);
        students[i].score = students[i].math + students[i].chinese + students[i].english;
    }

    // 排序
    // int j;
    // stu tmp;
    // for (i = 0; i < n - 1; i++)
    // {
    //     for (j = i; j < n - 1; j++)
    //     {
    //         // if (students[j].score < students[j + 1].score)
    //         // {
    //         //     // 交换
    //         //     tmp = students[j];
    //         //     students[j] = students[j + 1];
    //         //     students[j + 1] = tmp;
    //         // }
    //         // else if (students[j].score == students[j + 1].score && students[j].chinese < students[j + 1].chinese)
    //         // {
    //         //     tmp = students[j];
    //         //     students[j] = students[j + 1];
    //         //     students[j + 1] = tmp;
    //         // }
    //         // else if (students[j].score == students[j + 1].score && students[j].chinese == students[j + 1].chinese && students[j].math < students[j + 1].math)
    //         // {
    //         //     tmp = students[j];
    //         //     students[j] = students[j + 1];
    //         //     students[j + 1] = tmp;
    //         // }

    //         if (compare(students[j], students[j + 1]) < 0)
    //         {
    //             tmp = students[j];
    //             students[j] = students[j + 1];
    //             students[j + 1] = tmp;
    //         }
    //     }
    // }

    // O(nlogn)
    qsort(students, n, sizeof(stu), cmp_stu);

    // 输出
    for (i = 0; i < n; i++)
    {
        printf("%20s %d", students[i].name, students[i].score);
    }

    return 0;
}
