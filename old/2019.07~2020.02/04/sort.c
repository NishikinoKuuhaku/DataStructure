#include<stdio.h>
int main()
{
	int i;
	int j;
	int k,x,y;

	int a[100];
	scanf("%d",&y);
	for(i=0;i<y;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<y-1;i++)
	{
		for(j=0;j<y-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	scanf("%d",&x);

	if (x == 1)
	{
		printf("-1");
	}
	else
	{
		printf("%d", a[x - 2]);
	}

	printf(" %d ", a[x - 1]);

	if (x == y)
	{
		printf("-1");
	}
	else
	{
		printf("%d", a[x]);
	}

	// printf("%d %d %d ",a[x-2],a[x-1],a[x]);
}
