#include<stdio.h> 
int main()
{
	int i ;         
	int j ;      
	int k,x,len;  
	int a[100];
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}    
	for(i=0;i<len-1;i++)
	{
		int min = i;
		for(j = i + 1;j < len; j++)
		{
			if(a[j] < a[min])
			{
				int temp = a[j];
				a[j] = a[min];
				a[min] = temp; 
			}
		}
	}
	
	scanf("%d",&x);	
	if (x == 1)
	{
		printf("-1");
		printf(" %d %d",a[0],a[1]);
	}		
	else
	{
		printf("%d %d %d ",a[x-2], a[x],a[x-1]);
	}
	if (x == len)
	{
		printf("-1");
		printf(" %d %d",a[len-1],a[len-2]);
	}
	//printf("%d %d %d ",a[x],a[x-2],a[x-1]);
}
