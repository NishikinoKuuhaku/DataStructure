#include <stdio.h>
#include <stdlib.h>

typedef struct BidirectionalLinkedList
{
	int val;
	struct BidirectionalLinkedList *next, *prev;
}BLL;

// 创建一个空链表，将首尾节点的指针写入传入的指针地址中
void createLinkedList(BLL **head, BLL **tail)
{
    BLL *node = (BLL *)malloc(sizeof(BLL));
    BLL *link = (BLL *)malloc(sizeof(BLL));
    *tail = node;
    *head = link;
    link->next = node;
    link->prev = NULL;
    link->val = 0;
    node->prev = link;
    node->next = NULL;
    node->val = 0;
}

// 创建一个值为 value 的节点，并将它插入在链表的首位
void insertHead(BLL *head, BLL *tail, int value)
{
    BLL *node = (BLL *)malloc(sizeof(BLL));
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->val = value;
}

// 创建一个值为 value 的节点，并将它插入在链表的末尾
void insertTail(BLL *head, BLL *tail, int value)
{
    BLL *node = (BLL *)malloc(sizeof(BLL));
    node->prev = tail->prev;
    node->next = tail;
    tail->prev->next = node;
    tail->prev = node;
    node->val = value;
}

// 删除链表的首个元素
void deleteHead(BLL *head, BLL *tail)
{
    BLL *node = head->next;
    head->next = head->next->next;
    node->next->prev = head;
    free(node);
}

// 删除链表的末位元素
void deleteTail(BLL *head, BLL *tail)
{
    BLL *node = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    free(node);
}

// 遍历链表，并将其中每个元素依次写入 rval 数组（空间已申请），并在最后将链表的大小写入 ll_size
void walk(BLL *head, BLL *tail, int *rval, int *ll_size)
{
    BLL *node = head->next;
    int *tmp = 0;
    // while (node != NULL)
    // {
    //     /* code */
    //     *rval = node->val;
    //     node = node->next;
    //     tmp++;
    // }
    int i;
    for (i = 0; node != tail; i++)
    {
        /* code */
        rval[i] = node->val;
        node = node->next;
    }
    *ll_size = i;
}

int main()
{
    BLL *head, *tail;
    int rval[10] = {0}, size = 0;

    createLinkedList(&head, &tail);
    // 此时链表内容为空
    insertHead(head, tail, 0);
    insertHead(head, tail, 1);
    insertHead(head, tail, 2);
    insertTail(head, tail, 3);
    insertTail(head, tail, 4);
    // 此时链表内容为 2 - 1 - 0 - 3 - 4
    deleteHead(head, tail);
    //1-0-3-4
    deleteTail(head, tail);
    //1-0-3
    insertTail(head, tail, 5);
    deleteTail(head, tail);
    deleteTail(head, tail);
    insertHead(head, tail, 6);
    deleteTail(head, tail);
    // 此时链表内容为 6 - 1
    walk(head, tail, rval, &size);
    // 此时 rval[0] = 6, rval[1] = 1, size = 2
    return 0;
}
