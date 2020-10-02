#include <stdio.h>

void *convert(void *input, int mode, int encode)
{
    /* Code Here */
}

int main(int argc, char const *argv[])
{
    int in1 = 16;
    char *r1 = (char *)convert(&in1, 1, 16);
    printf("%s", r1);

    char in2 = "1000";
    int *r2 = (int *)convert(&in2, 0, 2);
    printf("%d", r2);

    return 0;
}
