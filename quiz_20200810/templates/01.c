#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} RLL;

RLL *newNode(int data)
{
	RLL *p;
	p = (RLL *)malloc(sizeof(RLL));
	p->val = data;
	p->next = NULL;
	return p;
}

int getLenOfRLL(RLL *head)
{
}

int main(int argc, char const *argv[])
{
	int len = 5;

	RLL *head, *p;
	head = newNode(0);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(i);
		p = p->next;
	}
	p->next = head;

	printf("%d", getLenOfRLL(head)); // print "5"

	return 0;
}
