#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}LL;

LL *newNode(int data)
{
	LL *p;
	p = (LL *)malloc(sizeof(LL));
	p->val = data;
	p->next = NULL;
	return p;
}

int kthToLast(LL *head, int k)
{
	/*Your Code Here*/
}

int main(int argc, char const *argv[])
{
	int data[] = {100, 97, 92, 98, 95};
	int len = 5;
	int k = 2;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

    printf("%d", kthToLast(head, k)); // print "98"

    return 0;
}
