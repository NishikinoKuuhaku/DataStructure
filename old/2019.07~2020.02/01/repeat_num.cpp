#include <stdio.h>
int main()
{
	int i, j;
	int a[9];
	for (i = 0; i <= 8; i++)
	{
		scanf("%d\n", &a[i]);
	}
	for (i = 8; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}
