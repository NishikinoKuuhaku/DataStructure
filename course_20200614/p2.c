#include <stdio.h>

struct student
{
    int score;
    int chinese, math, english;
    char name[20];
};

typedef struct student stu;

int main(int argc, char const *argv[])
{
    stu students[100];

    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, students[i].math, students[i].chinese, students[i].english);
        students[i].score = students[i].math + students[i].chinese + students[i].english;
    }

    int j;
    stu tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n - 1; j++)
        {
            if (students[j].score < students[j + 1].score)
            {
                tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
            else if (students[j].score == students[j + 1].score && students[j].chinese < students[j + 1].chinese)
            {
                tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
            else if (students[j].score == students[j + 1].score && students[j].chinese == students[j + 1].chinese && students[j].math < students[j + 1].math)
            {
                tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%20s %d", students[i].name, students[i].score);
    }

    return 0;
}
