#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

char *convert(char *s, int n0, int n1)
{
}

int main(int argc, char const *argv[])
{
    char s[] = "233";
    int n0 = 4, n1 = 16;

    printf("%s", convert(s, n0, n1)); // print "101111"

    return 0;
}
