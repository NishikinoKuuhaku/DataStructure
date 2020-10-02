#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
	char name[50];
	int count;
	struct book *next;
} book;

book *newNode(char name[])
{
	book *tmp;
	tmp = (book *)malloc(sizeof(book));
	strcpy(tmp->name, name);
	tmp->count = 1;
	tmp->next = NULL;
	return tmp;
}

book *search(char name[], book *head)
{
	book *p = head;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}

book *insert(book *elem, book *head)
{
	elem->next = head;
	return elem;
}

void print(book *head)
{
	book *p;
	p = head;
	while (p != NULL)
	{
		if (p->count != 0)
			printf("%s %d\n", p->name, p->count);
		p = p->next;
	}
}

int main()
{
	int n, flag;
	char name[50];
	book *p, *head, *tmp;
	p = head = NULL;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %s", &flag, name);
		if (flag == 0)
		{
			p = search(name, head);
			if (p == NULL || p->count == 0)
			{
				printf("error\n");
				return 0;
			}
			p->count--;
		}
		else
		{
			p = search(name, head);
			if (p == NULL)
			{
				tmp = newNode(name);
				head = insert(tmp, head);
			}
			else
				p->count++;
		}
	}
	print(head);
	return 0;
}
