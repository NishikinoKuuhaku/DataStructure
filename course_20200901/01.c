#include <stdio.h>
#include <stdlib.h>

typedef struct BidirectionalLinkedList
{
    int val;
    struct BidirectionalLinkedList *next, *prev;
} BLL;

BLL *createNode(int val)
{
    BLL *node = (BLL *)calloc(1, sizeof(BLL)); // calloc(a, b) 申请 a 份，每份大小为 b 的内存，并把这些内存初始化为 0
    node->val = val;
    return node;
}

// 创建一个空链表，将首尾节点的指针写入传入的指针地址中
void createLinkedList(BLL **head, BLL **tail)
{
    *head = createNode(0);
    *tail = createNode(0);
    (*head)->next = *tail;
    (*tail)->prev = *head;
}

// 创建一个值为 value 的节点，并将它插入在链表的首位
void insertHead(BLL *head, BLL *tail, int value)
{
    BLL *node = createNode(value);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

// 创建一个值为 value 的节点，并将它插入在链表的末尾
void insertTail(BLL *head, BLL *tail, int value)
{
    BLL *node = createNode(value);
    node->next = tail;
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
}

// 删除链表的首个元素
int deleteHead(BLL *head, BLL *tail)
{
    BLL *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    int val = tmp->val;
    free(tmp);
    return val;
}

// 删除链表的末位元素
int deleteTail(BLL *head, BLL *tail)
{
    BLL *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    int val = tmp->val;
    free(tmp);
    return val;
}

// 遍历链表，并将其中每个元素依次写入 rval 数组（空间已申请），并在最后将链表的大小写入 ll_size
void walk(BLL *head, BLL *tail, int *rval, int *ll_size)
{
    int size = 0;
    BLL *curr = head->next;
    while (curr != tail)
    {
        rval[size] = curr->val;
        curr = curr->next;
        size++;
    }
    *ll_size = size;
}