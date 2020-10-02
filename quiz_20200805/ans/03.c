#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addStrings(char *num1, char *num2)
{
    /*Your Code Here*/
    int len1, len2;
    len1 = strlen(num1);
    len2 = strlen(num2);
    char *num3 = malloc(sizeof(char));
    if (le1 == len2)
    {
        /* code */
        for (size_t i = 0; i < len1; i++)
        {
            /* code */
            num3[i] = num1[i] + num2[i];
        }
        return num3
    }
}

int main(int argc, char const *argv[])
{
    char num1[] = "11111123", num2[] = "44444444444444444456";

    printf("%s", addStrings(num1, num2)); // print "579"

    return 0;
}
