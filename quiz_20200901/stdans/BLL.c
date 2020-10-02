#include <stdio.h>
#include <stdlib.h>

#ifndef BLL_DATA_TYPE
#define BLL_DATA_TYPE void *
#endif

typedef struct BidirectionalLinkedList
{
    BLL_DATA_TYPE val;
    struct BidirectionalLinkedList *next, *prev;
} BLL;

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
void insertHead(BLL *head, BLL *tail, BLL_DATA_TYPE value)
{
    BLL *node = (BLL *)malloc(sizeof(BLL));
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->val = value;
}

// 创建一个值为 value 的节点，并将它插入在链表的末尾
void insertTail(BLL *head, BLL *tail, BLL_DATA_TYPE value)
{
    BLL *node = (BLL *)malloc(sizeof(BLL));
    node->prev = tail->prev;
    node->next = tail;
    tail->prev->next = node;
    tail->prev = node;
    node->val = value;
}

// 删除链表的首个元素
BLL_DATA_TYPE deleteHead(BLL *head, BLL *tail)
{
    BLL *node = head->next;
    head->next = head->next->next;
    node->next->prev = head;
    BLL_DATA_TYPE rval = node->val;
    free(node);
    return rval;
}

// 删除并返回链表的末位元素
BLL_DATA_TYPE deleteTail(BLL *head, BLL *tail)
{
    BLL *node = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    BLL_DATA_TYPE rval = node->val;
    free(node);
    return rval;
}

// 遍历链表，并将其中每个元素依次写入 rval 数组（空间已申请）
// 如果 ll_size 非 NULL ，则将链表的大小写入它
void walk(BLL *head, BLL *tail, BLL_DATA_TYPE *rval, int *ll_size)
{
    BLL *node = head->next;
    int i;
    for (i = 0; node != tail; i++)
    {
        /* code */
        rval[i] = node->val;
        node = node->next;
    }
    if (ll_size != NULL)
    {
        *ll_size = i;
    }
}
