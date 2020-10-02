#include <stdio.h>

void print1()
{
    printf("1\n");
}

void print2()
{
    printf("2\n");
}

void printn(int n)
{
    printf("%d\n", n);
}

void print2n(int n)
{
    printf("%d\n", n * 2);
}

void run(void function(int))
{
    for (size_t i = 0; i < 10; i++)
    {
        function(i);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    run(printn);
    return 0;
}
