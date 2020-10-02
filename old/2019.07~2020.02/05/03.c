#include <stdio.h>
int main()
{
	int i, j;
	int k;
	float temp, min, max;
	float a[1000];
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		scanf("%f", &a[i]);
	}
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%.2f\n", a[i]);
	}

	getchar();
	getchar();
	return 0;
}