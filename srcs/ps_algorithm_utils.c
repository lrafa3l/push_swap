
#include "../incs/push_swap.h"

void    put_index(t_stack *stack)
{
    int index;
    int up_middle;

    index = 0;
    up_middle = count_elem(stack) / 2;
    if (!stack)
        return ;
    while (stack)
    {
        stack->index = index;
        if (index <= up_middle)
            stack->up_middle = 1;
        else
            stack->up_middle = 0;
        stack = stack->next;
        index++;
    }
}