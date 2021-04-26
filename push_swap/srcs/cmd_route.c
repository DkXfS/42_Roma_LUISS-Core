#include "header.h"

void    command_route(t_stack **a, t_stack *b, char *cmd)
{
    while (get_next_line(0, &cmd) > 0)
    {
        if(*cmd == 'r' && *(cmd + 1) == 'r' && *(cmd + 2) == 'a')
            *a = reverse_rotate(*a);
        else if(*cmd == 'r' && *(cmd + 1) == 'r' && *(cmd + 2) == 'b')
            b = reverse_rotate(b);
        else if(*cmd == 'r' && *(cmd + 1) == 'r' && *(cmd + 2) == 'r')
        {
            *a = reverse_rotate(*a);
            b = reverse_rotate(b);
        }
        else if(*cmd == 's' && *(cmd + 1) == 'a')
            swap(*a);
        else if(*cmd == 's' && *(cmd + 1) == 'b')
            swap(b);
        else if(*cmd == 's' && *(cmd + 1) == 's')
            double_swap(*a, b);
        else if(*cmd == 'p' && *(cmd + 1) == 'a')
            push(a, &b);
        else if(*cmd == 'p' && *(cmd + 1) == 'b')
            push(&b, a);
        else if(*cmd == 'r' && *(cmd + 1) == 'a')
            *a = rotate(*a);
        else if(*cmd == 'r' && *(cmd + 1) == 'b')
            b = rotate(b);
        else if(*cmd == 'r' && *(cmd + 1) == 'r')
        {
            *a = rotate(*a);
            b = rotate(b);
        }
        free(cmd);
    }
}