#include <stdio.h>
int main()
{
	int n;
	double pay = 0, l;
	scanf("%d", &n);
	if (n > 400)
	{
		l = 400 * 0.5663;
		pay = l + (n - 400) * 0.5663, n = 400;
	}
	if (n > 150)
	{
		l = 150 * 0.4663;
		pay = l + (n - 150) * 0.4663;
		n = 150;
	}
	if (n < 150)
	{
		l = 150 * 0.4463;
		pay = pay + n * 0.4463;
	}
	printf("%1lf", pay);
	// getchar();
	// getchar();
	return 0;
}
