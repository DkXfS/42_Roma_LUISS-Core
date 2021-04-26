#include "header.h"

void    swap(t_stack *stk)
{
    int val;

    if (stk && stk->next)
    {
        val = stk->num;
        stk->num = stk->next->num;
        stk->next->num = val;
    }
}

void    push(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b)
    {
        if (*a)
        {
            if ((*b)->next)
                (*b)->next->prev = NULL;
            temp = (*b);
            (*b) = (*b)->next;
            (*a)->prev = temp;
            temp->next = (*a);
            (*a) = temp;
        }
        else
        {
            if ((*b)->next)
                (*b)->next->prev = NULL;
            temp = (*b);
            (*b) = (*b)->next;
            (*a) = temp;
            (*a)->next = NULL;
        }
    }
}

t_stack *rotate(t_stack *stk)
{
    t_stack *temp;
    t_stack *temp2;

    temp = stk;
    temp2 = stk->next;
    while (stk->next)
        stk = stk->next;
    stk->next = temp;
    temp->next = NULL;
    return (temp2);
}

t_stack *reverse_rotate(t_stack *stk)
{
    t_stack *temp;

    temp = stk;
    while (stk->next)
        stk = stk->next;
    stk->prev->next = NULL;
    temp->prev = stk;
    stk->next = temp;
    stk->prev = NULL;
    return (stk);
}

void    double_swap(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}