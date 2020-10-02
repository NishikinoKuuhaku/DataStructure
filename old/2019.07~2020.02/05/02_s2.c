#include <stdio.h>

int main(int argc, char const *argv[])
{
    char input[20], min[20];
    int n, i, lowest, inHeight;

    scanf("%d", &n);

    lowest = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &inHeight, input);
        if (i > 0)
        {
            if (inHeight < lowest)
            {
                lowest = inHeight;
                strcpy(min, input);
            }
        }
        else
        {
            lowest = inHeight;
            strcpy(min, input);
        }
    }

    printf("%s %d", min, lowest);

    return 0;
}