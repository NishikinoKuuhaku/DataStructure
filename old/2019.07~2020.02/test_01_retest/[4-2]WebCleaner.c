#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char forbid[20][10]; // 敏感词
    char id[10][10], tmp[10];  // id 表和临时存储输入 id 的数组
    char idNum = 0, count[10]; // id 个数和对应 id 的违规次数
    int n, m, i, j, k, l;

    scanf("%d", &n);
    for (i = 0; i < n; i++) // 输入敏感词
    {
        scanf("%s", forbid[i]);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        char content[150];
        int currentID;
        scanf("%s %s",tmp , content);
        tmp[strlen(tmp) - 1] = 0; // 去掉冒号

        for (j = 0; j < idNum; j++) // 查找此id是否在表中
        {
            if(strcmp(id[j], tmp) == 0)
            {
                currentID = j;
                break;
            }
        }
        if(j==0 || j==idNum) // id 不在表中的情况
        {
            strcpy(id[idNum], tmp);
            idNum++;
            currentID = j;
        }

        // 查找是否有敏感词
        for (j = 0; j < n; j++) // 每个敏感词都要查
        {
            for (k = 0; k < strlen(content); k++) // 主循环
            {
                for (l = k; l < k + strlen(forbid[j]); l++) // 若找到了匹配的首字母，从这里开始和敏感词对比                {
                    if(content[l] != forbid[j][l-k])
                    {
                        break; // 二者不一样就退出循环
                    }
                }
                if(l == k + strlen(forbid[j])) // 找到敏感词
                {
                    count[currentID]++; // 计数
                    for (l = k; l < k + strlen(forbid[j]); l++) // 替换内容
                    {
                        content[l] = '*';
                    }
                }
            }
        }

        printf("%s: %s\n", tmp, content); // 直接输出即可，不需要存下来
    }

    int max = 0; // 经典的找最大值
    for (i = 0; i < idNum; i++)
    {
        if(count[i] > count[max])
        {
            max = i;
        }
    }

    printf("*system*: %s is banned for talking aggressively", id[max]);

    getchar();
    getchar();
    return 0;
}
