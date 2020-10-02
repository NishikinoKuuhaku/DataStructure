#include <stdio.h>
#include <stdlib.h>

typedef struct RBLL
{
	int data;
	struct RBLL *next, *prev;
} RBLL;

RBLL *getNewNode(int data)
{
	RBLL *tmp;
	tmp = (RBLL *)malloc(sizeof(RBLL *));
	tmp->data = data;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

RBLL *create(int data)
{
	RBLL *head;
	head = (RBLL *)malloc(sizeof(RBLL *));
	head->data = data;
	head->next = head->prev = head;
	return head;
}

void insert(RBLL *elem, RBLL *prev)
{
	prev->next->prev = elem;
	elem->prev = prev;
	elem->next = prev->next;
	prev->next = elem;
	return;
}

void deleteNode(RBLL *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	free(elem);
	return;
}

int main()
{
	int n, i, sum, count;
	RBLL *head = NULL, *tmp = NULL, *p = NULL;
	scanf("%d", &n);
	p = head = create(1);
	for (i = 2; i <= n; i++)
	{
		tmp = getNewNode(i);
		insert(tmp, p);
		p = tmp;
	}
	count = 1;
	sum = n;
	p = head;
	while (sum > 1)
	{
		if (count == 5)
		{
			tmp = p->next;
			deleteNode(p);
			p = tmp;
			sum--;
			count = 1;
			continue;
		}
		p = p->next;
		count++;
	}
	printf("%d", p->data);
	return 0;
}
