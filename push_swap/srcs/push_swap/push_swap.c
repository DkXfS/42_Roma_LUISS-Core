#include "header.h"

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

void    push_swap(t_stack *a, t_stack *b)
{
    t_moves min_moves;
    int min_num;
    int i;
    t_stack *temp;
    t_moves moves;

    min_moves.total = -1;
    min_num = -1;
    i = 0;
    write(1, "pb\n", 2);
    push(&b, &a);
    write(1, "pb\n", 2);
    push(&b, &a);
    temp = a;
    while (temp)
    {
        moves = calc_moves(i, temp, b);
        if(moves.total < min_moves.total || min_moves.total < 0)
        {
            min_moves = moves;
            min_num = temp->num;
        }
        temp = temp->next;
        i++;
    }
//  make_move(&a, &b, min_moves, min_num)
}

// void    push_swap(t_stack *a, t_stack *b, int avg)
// {
//     while (a)
//     {
//         if (a->num > avg)
//         {
//             write(1, "pb\n", 2);
//             push(&b, &a);
//         }
//         else
//         {
//             write(1, "ra", 2);
//             a = rotate(a);
//         }
//     }
// }

int main(int argc, char **argv)
{
    t_stack *main_stack;
//    t_stack *b;
    
    main_stack = make_stack(argc, argv);
//  push_swap(main_stack, NULL, stack_average(main_stack));
    push_swap(main_stack, NULL);
}
