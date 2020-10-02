#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a, b, c;
    int s;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c&&b + c > a&&a + c > a)
    {
        s = (a + b + c) / 2;

        if (a == b&&a == c)
        {
            printf("锐角三角形\n");
        }

        else if (a == b || a == c || b == c)
        {
            printf("钝角三角形\n");
        }

        else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
        {
            printf("直角三角形\n");
        }
    	else
    	{
    		printf("not triangle\n");
    	}
    }

}