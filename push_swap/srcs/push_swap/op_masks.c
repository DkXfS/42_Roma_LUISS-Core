#include "header.h"

void    ra(t_stack **stk)
{
    *stk = rotate(*stk);
    write(1, "ra\n", 3);
}

void    rb(t_stack **stk)
{
    *stk = rotate(*stk);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    *a = rotate(*a);
    *b = rotate(*b);
    write(1, "rr\n", 3);
}

void    rra(t_stack **a)
{
    *a = reverse_rotate(*a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    *b = reverse_rotate(*b);
    write(1, "rrb\n", 4);
}