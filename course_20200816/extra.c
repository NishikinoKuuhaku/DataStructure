#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arr_stack
{
    int size;
    int maxsize;
    int *elements;
} ArrStack;

void push(ArrStack *stk, int elem)
{
    if (stk->size >= stk->maxsize)
    {
        stk->maxsize++;
        int *new_elements = malloc(sizeof(int) * stk->maxsize);
        memcpy(new_elements, stk->elements, stk->size);
        free(stk->elements);
        stk->elements = new_elements;
    }
    stk->elements[stk->size] = elem;
    stk->size++;
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
    stk.maxsize = 10;
    stk.elements = malloc(sizeof(int) * stk.maxsize);
    return stk;
}

int main(int argc, char const *argv[])
{

    return 0;
}
