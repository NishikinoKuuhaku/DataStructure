#include <stdio.h>
#include <string.h>

void insert(char *base, char *insert, int pos)
{
    /* Code Here */
}

int main(int argc, char const *argv[])
{
    char base[1000] = "bull";
    char insert[1000] = "shit";
    int pos = 4;

    insert(base, insert, pos);

    printf("%s", base);
    return 0;
}
