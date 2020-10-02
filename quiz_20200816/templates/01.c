#include <stdio.h>
#include<stdlib.h>

typedef struct LinkList
{
	int data;
	struct LinkList *next;
} LinkList;

typedef struct queue
{
	struct LinkList *front;
	struct LinkList *rear;
}Linkqueue;

Linkqueue *createqueue(void)
{
	Linkqueue *plqu;
	plqu = (Linkqueue *)malloc(sizeof(Linkqueue));
	if(plqu != NULL)
	{
		plqu->front = NULL;
		plqu->rear = NULL;
	}
	else
	{
		printf("error\n");
	}
	return plqu;
}

int inqueue(Linkqueue *plqu,int data)
{
	LinkList *node;
	node = (LinkList *)malloc(sizeof(LinkList));
	if(plqu == NULL)
	{
		printf("in pnew malloc is fail\n");
        return -1;
	}
	else
	{
		node->data = data;
		node->next = NULL;
		if(plqu->front == NULL) plqu->front = node;
		else plqu->rear->next = node;
		plqu->rear = node;
		return 1;
	}
}

int outqueue(Linkqueue *plqu)
{
	LinkList *node = NULL;
	if(plqu == NULL)
	{
		printf("Empty queue.\n");
	}

	else
	{
		node = plqu->front;
		plqu->front = node->next;
		if (plqu->front == NULL)
		{
			/* code */
			plqu->rear = NULL;
		}

		free(node);
	}
}

int is_queue_empty(Linkqueue *plqu)
{
	return((plqu->front == NULL) ? 1 : 0);
}
void showqueue(Linkqueue *plqu)
{
	if(plqu == NULL)
	{
		printf("erreeo\n");

	}
	if(is_queue_empty(plqu) == 1)
	{
		printf("erreo\n");
	}
	LinkList *node = plqu->front;
	while(node != NULL)
	{
		printf("%d\n",node->data);
		node = node->next;
	}
}

void bankManage(int n, int flag[], int data[])
{
	/*Your Code Here*/
	int i;
	int data_flag = 0;
	Linkqueue *plqu = NULL;
	plqu = createqueue();
	for(i = 0;i < n; i++)
	{
		/* code */
		if(flag[i] == 1)
		{
			outqueue(plqu);
		}
		else
		{
			inqueue(plqu,data[data_flag]);
			data_flag++;
		}
	}
	showqueue(plqu);
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int flag[] = {0, 0, 0, 1, 0};
	int data[] = {15, 20, 4, 7};
	// int n = 2;
	// int flag[] = {0, 1};
	// int data[] = {15, 20};

	bankManage(n, flag, data);

    return 0;
}
