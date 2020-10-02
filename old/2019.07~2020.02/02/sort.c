#include<stdio.h>
int main()
{
	int n,j,l;
	scanf("%d",&n);
	// if(n<=100)
	// {
		int a[100];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		// if(-2147483648<=a[n]<=+2147483647)
		// {
			for(j=0;j<n-1;j++)
			{
				for(l=0;l<n-j;l++)
				{
					if(a[l]>a[l+1])
					{
						int temp=a[l];
						a[l]=a[l+1];
						a[l+1]=temp;
					}
				}
			}
		// }
		for(j=0;j<n;j++)
		{
			printf("%d",a[j]);
		}
	// }
 } 
