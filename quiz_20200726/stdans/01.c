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
void deleteHead(BLL *head, BLL *tail)
{
    BLL *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    free(tmp);
}

// 删除链表的末位元素
void deleteTail(BLL *head, BLL *tail)
{
    BLL *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    free(tmp);
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

int main(int argc, const char *argv[])
{
    BLL *head, *tail;
    int rval[10] = {}, size;

    createLinkedList(&head, &tail);
    // 此时链表内容为空
    insertHead(head, tail, 0);
    insertHead(head, tail, 1);
    insertHead(head, tail, 2);
    insertTail(head, tail, 3);
    insertTail(head, tail, 4);
    // 此时链表内容为 2 - 1 - 0 - 3 - 4
    deleteHead(head, tail);
    deleteTail(head, tail);
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
