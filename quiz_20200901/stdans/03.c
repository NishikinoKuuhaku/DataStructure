#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 1000

int myStrlen(char *s)
{
    int l = 0;
    while (*s)
    {
        s++;
        l++;
    }
    return l;
}

void myStrcpy(char *s, char *dest)
{
    do
    {
        *dest = *s;
        dest++;
        s++;
    } while (*s);
}

void stringEdit(char *s, int mode, int pos, void *content)
{
    char tmp[MAX_STR_LEN];
    int len_insert;
    int len_original = myStrlen(s);
    switch (mode)
    {
        // insert
        case 1:
            len_insert = myStrlen((char *)content);
            myStrcpy(s + pos, tmp);
            myStrcpy((char *)content, s + pos);
            myStrcpy(tmp, s + pos + len_insert);
            s[len_original + len_insert] = 0;
            break;
        // delete
        case 2:
            myStrcpy(s + pos + *((int *)content), tmp);
            myStrcpy(tmp, s + pos);
            s[len_original - *((int *)content)] = 0;
            break;
        default:
            printf("error mode code: %d", mode);
            break;
    }
}

int main(int argc, char const *argv[])
{
    char s[MAX_STR_LEN] = "abcdefg";
    char insert[] = "00000";
    int pos = 2;
    stringEdit(s, 2, 3, &pos);
    stringEdit(s, 1, 0, insert);
    printf("%s", s); // print "00000abcfg"
    return 0;
}
