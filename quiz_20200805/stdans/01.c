#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} LL;

LL *newNode(int data)
{
	LL *p;
	p = (LL *)malloc(sizeof(LL));
	p->val = data;
	p->next = NULL;
	return p;
}

void printHexValueOfLinkedList(LL *head)
{
	int size, i, j, value[1000], mod, tmp;
	char s[] = "0123456789abcdef";
	LL *p;
	size = 0;
	p = head;
	while (p != NULL)
	{
		value[size++] = p->val;
		p = p->next;
	}
	mod = size % 4;
	tmp = 0;
	for (i = 0; i < mod; i++)
	{
		tmp = tmp * 2 + value[i];
	}
	printf("%c", s[tmp]);
	while (i < size)
	{
		tmp = 0;
		for (j = 0; j < 4; j++)
		{
			tmp = tmp * 2 + value[i + j];
		}
		i += 4;
		printf("%c", s[tmp]);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int data[] = {1, 0};
	int len = 2;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

	printHexValueOfLinkedList(head); // print “49c0”

	return 0;
}
