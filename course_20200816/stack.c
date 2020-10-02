#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

typedef struct arr_stack
{
    int size;
    int elements[MAX_STACK_SIZE];
} ArrStack;

void push(ArrStack *stk, int elem)
{
    if (stk->size >= MAX_STACK_SIZE)
    {
        printf("错误！尝试向满的栈中存放元素！");
    }
    else
    {
        stk->elements[stk->size] = elem;
        stk->size++;
    }
}

int pop(ArrStack *stk)
{
    if (is_stack_empty(stk))
    {
        printf("错误！尝试从空的栈中取出元素！");
        return -1;
    }
    else
    {
        stk->size--;
        return stk->elements[stk->size];
    }
}

int is_stack_empty(ArrStack *stk)
{
    return (stk->size == 0) ? 1 : 0;
}

ArrStack init_stack()
{
    ArrStack stk;
    stk.size = 0;
    return stk;
}

int main(int argc, char const *argv[])
{

    return 0;
}
