#include "BLL.c"

typedef struct BLLObject
{
    int size;
    BLL *head, *tail;
} BLLObject;

// 定义 BLLObject 的别名 BLLQueue, BLLStack
typedef BLLObject BLLQueue;
typedef BLLObject BLLStack;

// 返回一个初始化后的 BLLObject 变量
BLLObject init_obj()
{
    BLLObject obj;
    obj.size = 0;
    createLinkedList(&obj.head, &obj.tail);
    return obj;
}

// 定义 init_obj 的别名 init_queue, init_stack
#define init_queue() init_obj()
#define init_stack() init_obj()

// 将 BLLObject 中的内容表示为数组，存入 arrp 指向的地址
void to_array(BLLObject *obj, BLL_DATA_TYPE **arrp)
{
    *arrp = (BLL_DATA_TYPE *)calloc(obj->size, sizeof(BLL_DATA_TYPE));
    walk(obj->head, obj->tail, *arrp, NULL);
}

void in_queue(BLLObject *obj, BLL_DATA_TYPE newval)
{
    obj->size++;
    insertTail(obj->head, obj->tail, newval);
}

BLL_DATA_TYPE out_queue(BLLObject *obj)
{
    obj->size--;
    return deleteHead(obj->head, obj->tail);
}

void push(BLLObject *obj, BLL_DATA_TYPE newval)
{
    obj->size++;
    insertTail(obj->head, obj->tail, newval);
}

BLL_DATA_TYPE pop(BLLObject *obj)
{
    obj->size--;
    return deleteTail(obj->head, obj->tail);
}
