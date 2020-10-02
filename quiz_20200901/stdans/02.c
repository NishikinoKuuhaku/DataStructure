#define BLL_DATA_TYPE int

#include "BLLObject.c"

int posOfFile(int *history, int lookup)
{
    BLLStack stk = init_stack();
    while (*history != 0)
    {
        if (*history > 0)
        {
            push(&stk, *history);
        }
        else
        {
            for (size_t i = 0; i < -(*history); i++)
            {
                pop(&stk);
            }
        }
        history++;
    }
    int pos = -1;
    int curr_pos = 0;
    while (stk.size > 0)
    {
        int elem = pop(&stk);
        if (elem == lookup)
        {
            pos = curr_pos;
            break;
        }
        curr_pos++;
    }
    return pos;
}

int main(int argc, char const *argv[])
{
    int history[] = {1, 2, 3, 4, 5, -2, 6, 7, 8, 9, -3, 10, 11, -1, -2, 0};
    int lookup = 1;

    printf("%d", posOfFile(history, lookup));

    return 0;
}
