#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0;
	int np = 0;
	int ntemp = 0;
	char str[1000];
	int num[1000];
	char act[1000]={0};
	gets(str);
	int len,k=0;
	len = strlen(str);
	for ( i = 0; i < len+1; i++)
	{
		if (str[i]==' ')//忽略空格
		{
			continue;
		}
		if (str[i]>='0'&&str[i]<='9')//将字符串转换为数字
		{
			ntemp*=10;
			ntemp += str[i] - '0';
		}
		else if (ntemp!=0)//问题所在
		{
			num[np]=ntemp;
			np++;
			ntemp = 0;
		}
		if (ntemp==0&&str[i]=='0')
		{
			num[np]=0;
			np++;
			ntemp=0;
		}
	}
	if(np==0)//判断num数组里是否有数字
	{
		printf("-1\n");
	}
	for ( i = 0; i < np; i++)//求余输出
	{
		if (np!=0)
		{
			num[i] = num[i]%2019;
			printf("%d\n",num[i]);
		}

	}
	getchar();
	getchar();
	return 0;
}