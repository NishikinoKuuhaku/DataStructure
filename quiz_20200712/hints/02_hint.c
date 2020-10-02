#include <stdio.h>
#include <stdlib.h>

// 一个循环的双向链表
typedef struct RBLL
{
    int data;
    struct RBLL *next, *prev;
} RBLL;

//　给出一个数据，返回一个初始化后的节点
RBLL *getNewNode(int data)
{
}

// 给出首个节点的值，创建一个循环链表
RBLL *create(int data)
{
}

// 将 elem 插入 prev 后面
void *insert(RBLL *elem, RBLL *prev)
{
}

// 删除 elem
void *delete (RBLL *elem)
{
}