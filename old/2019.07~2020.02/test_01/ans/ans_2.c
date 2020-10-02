#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	int ap = 0, np = 0;
	int ntemp = 0;
	char str[1000];
	int num[1000] = {0};
	char act[1000] = {0};
	gets(str);
	int len, k = 0;
	len = strlen(str);
	for (i = 0; i < len + 1; i++)
	{
		if (str[i] == ' ')
		{
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			ntemp *= 10;
			ntemp += str[i] - '0';
		}
		else
		{
			act[ap] = str[i];
			ap++;
			num[np] = ntemp;
			np++;
			ntemp = 0;
		}
	}

	ntemp = strlen(act);
	for (i = 0; i < ntemp; i++)
	{
		if (act[i] == '-')
		{
			k = num[i] - num[i + 1];
			i++;
			for (ap = 1; ap < ntemp; ap++)
			{
				if (act[ap] == '+')
				{
					i++;
					k = k + num[i];
				}
				if (act[ap] == '-')
				{
					i++;
					k = k - num[i];
				}
			}
		}
		if (act[i] == '+')
		{
			k = num[i] + num[i + 1];
			i++;
			for (ap = 1; ap < ntemp; ap++)
			{
				if (act[ap] == '+')
				{
					i++;
					k = k + num[i];
				}
				if (act[ap] == '-')
				{
					i++;
					k = k - num[i];
				}
			}
		}
	}
	printf("%d\n", k);
	getchar();
	getchar();
	return 0;
}