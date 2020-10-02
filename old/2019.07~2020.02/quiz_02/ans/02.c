#include <stdio.h>
#include <string.h>

void newstr(char *base, char *insert, int pos)
{
    /* Code Here */
    int len1 = 0, len2 = 0, j = 0, k = 0;
    char s4[1000];
    len1 = strlen(base);
    len2 = strlen(insert);
    // for (int i = 0; i < pos; i++)
    // {
    //     j++;
    // }
    j = pos;
    k = pos;
    for (int i = pos; i < len1; i++)
    {
        s4[k++] = base[i];
    }
    for (int i = 0; i < len2; i++)
    {
        base[j++] = insert[i];
    }
    for (int i = pos; i < len1; i++)
    {
        base[j++] = s4[i];
    }
    base[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char base[1000] = "bull0123456789012345678901234567890123456789";
    char insert[1000] = "shit";
    int pos = 4;

    newstr(base, insert, pos);

    printf("%s", base);
    return 0;
}
