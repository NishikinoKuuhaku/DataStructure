#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} LL;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

LL *newNode(int data)
{
	LL *p;
	p = (LL *)malloc(sizeof(LL));
	p->val = data;
	p->next = NULL;
	return p;
}

int isLinkedListValid(LL *head)
{
	// 遍历头节点后的所有节点的同时加和
	LL *content = head->next;
	int target_valid = 0;
	int idx = 0;
	while (content != NULL)
	{
		target_valid += primes[idx] * content->val;
		content = content->next;
		idx++;
	}

	// 用三元表达式快速返回
	return (target_valid % 1009 == head->val) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
	int data[] = {1006, 1000, 0, 0, -1, 2};
	int len = 6;

	LL *head, *p;
	head = newNode(data[0]);
	p = head;
	for (size_t i = 1; i < len; i++)
	{
		p->next = newNode(data[i]);
		p = p->next;
	}

	printf("%d", isLinkedListValid(head)); // print 1

	return 0;
}
