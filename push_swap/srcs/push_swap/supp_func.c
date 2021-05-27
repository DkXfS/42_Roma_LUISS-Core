#include "header.h"

int calc_rb(t_stack *a, t_stack *b)
{
    int rb;

    rb = 0;
    while (a->num < b->num)
    {
        b = b->next;
        rb++;
    }
    return (rb);
}

t_moves init_moves(t_moves mv)
{
    mv.total = -1;
    mv.rra = 0;
    mv.rrr = 0;
    mv.rrb = 0;
    mv.rr = 0;
    mv.rb = 0;
    mv.ra = 0;
    return (mv);
}

int stack_average(t_stack *stk)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    while (stk)
    {
        temp += stk->num;
        stk = stk->next;
        i++;
    }
    return (temp / i);
}