#include <stdio.h>

int main(int argc, char const *argv[])
{
    char names[100][20];
    int height[100];
    int n, i, j;
    scanf("%s", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &height[i], names[i]);
    }

    int min = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (height[i] < height[min])
        {
            min = i;
        }
    }

    printf("%s %d", name[min], height[min]);

    return 0;
}