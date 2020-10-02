#include <stdio.h>

void printProb(int len, int arr[], double fin[])
{
    /* Code Here */
    int max;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < len; ++k)
    {
        max += arr[k];
    }
    for (int l = 0; l < len; ++l)
    {
        fin[l] = (double)arr[l] / max * 100;
        printf("%02d %.2lf%%\n", l + 1, fin[l]);
    }
}

int main(int argc, char const *argv[])
{
    int n = 12;
    int a[] = {125, 100, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    double fin[12] = {0};

    printProb(n, a, fin);

    return 0;
}
