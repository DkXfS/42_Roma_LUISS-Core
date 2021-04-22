#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_stack
{
    int num;
    struct s_stack *prev;
    struct s_stack *next;
}              t_stack;

void    swap(t_stack *stk);
void    push(t_stack *a, t_stack *b);
t_stack *rotate(t_stack *stk);
t_stack *reverse_rotate(t_stack *stk);

#endif