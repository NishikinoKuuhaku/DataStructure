#include <stdio.h>
#include <stdlib.h>

void test(void *p, int i)
{
    if (i == 0)
    {
        printf("%s\n", (char *)p);
    }
    if (i == 1)
    {
        printf("%d\n", *((int *)p));
    }
}

int *mallocTest()
{
    int *array;
    array = (int *)malloc(sizeof(int) * 5);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;

    int brray[5] = {1, 2, 3, 4, 5};

    int *crray = brray;

    return array;
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int *brr = &arr[3];
    printf("%d %d\n", arr[4], brr[2]);

    int *crr = arr + 1;
    printf("%d\n", crr[2]);

    float *fp = (float *)crr;
    printf("%f\n", *fp);

    int pp = 123456;
    char ppp[10] = "hello";

    test(ppp, 0);
    test(&pp, 1);

    int *array = mallocTest();
    printf("%d\n", array[1]);
    free(array);
    printf("%d\n", array[1]);

    return 0;
}
