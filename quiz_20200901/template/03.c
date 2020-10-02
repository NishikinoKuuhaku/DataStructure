#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 1000

int stringlen(char *s)
{
    int len = 0;
    while (*s++ != '\0')
    {
        len++;
    }
    return len;
}

void strinser(char *s,char *s2,int pos)
{
    int num1 = stringlen(s);
    int num2 = stringlen(s2);
    if (pos < 0 ||pos > num1 + 1)
    {

    }
    else
    {

    }

}

void stringEdit(char *s, int mode, int pos, void *content)
{
    if (mode == 1)
    {
        char *s2 = (char *)content;
        strinser(s, s2, pos);
    }
    else
    {

    }


}

int main(int argc, char const *argv[])
{
    char s[MAX_STR_LEN] = "abcdefg";
    char insert[] = "00000";
    int pos = 2;
    //stringEdit(s, 2, 3, &pos);
    stringEdit(s, 1, 0, insert);
    printf("%s", s); // print "00000abcfg"
    return 0;
}
