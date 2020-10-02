#include <stdio.h>

int isSubSeq(int *seqs, int lenA, int lenB)
{
    /* Code Here */
}

int main(int argc, char const *argv[])
{
    int lenA = 3, lenB = 1;
    int seqs[] = {5, 4, 3, 4};

    int r = isSubSeq(seqs, lenA, lenB);
    printf("%d", r);

    return 0;
}
