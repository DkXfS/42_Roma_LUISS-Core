#include "header.h"

void push_swap(t_stack *a, t_stack *b, int avg)
{
    while (a)
    {
        if (a->num >)
    }
}

int main(int argc, char **argv)
{
    int temp;
    int average_val;
    t_stack *main_stack;
    t_stack *a;
    
    main_stack = make_stack(argc, argv);
    a = main_stack;
    temp = 0;
    while (a)
    {
        temp += a->num;
        a = a->next;
    }
    average_val = temp / (argc - 1);
    push_swap(main_stack, NULL, average_val);
}