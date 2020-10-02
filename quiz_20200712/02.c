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
    RBLL *node = (RBLL *)malloc(sizeof(RBLL));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// 给出首个节点的值，创建一个循环链表
RBLL *create(int data)
{
    RBLL *linklist = getNewNode(data);
    linklist->next = linklist;
    linklist->prev = linklist;
    return linklist;
}

// 将 elem 插入 prev 后面
void insert(RBLL *elem, RBLL *prev)
{
    prev->next->prev = elem;
    elem->next = prev->next;
    elem->prev = prev;
    prev->next = elem;

}

// 删除 elem
void deletenode (RBLL *elem)
{
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    free(elem);
}
int main(int argc, char const *argv[])
{
    /* code */
    int size = 20;
    RBLL *head = create(1);
    RBLL *p = head;
    for (int i = 2; i <= size; i++)
    {
        RBLL *node = getNewNode(i);
        insert(node, p);
        p = node;
    }
    int temp = 1;
    p = head;
    while (size>1)
    {
        if (temp!=5)
        {
            /* code */
            p = p->next;
            temp++;
        }
        else
        {
            RBLL *tmpnode = p->next;
            deletenode (p);
            p = tmpnode;
            size--;
            temp = 1;
        }
    }
    printf("%d", p->data);

    return 0;
}