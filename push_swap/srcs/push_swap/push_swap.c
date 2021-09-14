#include "header.h"

void    rrr(t_stack **a, t_stack **b)
{
    *b = reverse_rotate(*b);
    *a = reverse_rotate(*a);
    write(1, "rrr\n", 4);
}

void    exec_moves(t_stack **a, t_stack **b, t_moves moves)
{
    while (moves.ra)
    {
        ra(a);
        moves.ra--;
    }
    while (moves.rb)
    {
        rb(b);
        moves.rb--;
    }
    while (moves.rr)
    {
        rr(a, b);
        moves.rr--;
    }
    while (moves.rra)
    {
        rra(a);
        moves.rra--;
    }
    while (moves.rrb)
    {
        rrb(b);
        moves.rrb--;
    }
    while (moves.rrr)
    {
        rrr(a, b);
        moves.rrr--;
    }
    push(b, a);
    write(1, "pb\n", 3);
}

t_moves    find_best_move(t_stack *a, t_stack *b, int a_length, int b_length)
{
    t_moves min_moves;
    t_moves moves;
    int ra;

    ra = 0;
    min_moves.total = -1;
    while (a)
    {
        moves = init_moves(moves);
        moves.num = a->num;
        moves.rb = calc_rb(a, b);
        moves = optimize(moves, a_length, b_length, ra);
        if(moves.total < min_moves.total || min_moves.total < 0)
            min_moves = moves;
        a = a->next;
        ra++;
    }
    return (min_moves);
}

void    push_swap(int a_length, int b_length, t_stack *a, t_stack *b)
{
    t_moves moves;

    write(1, "pb\n", 3);
    push(&b, &a);
    write(1, "pb\n", 3);
    push(&b, &a);
    a_length = a_length - 2;
    b_length = b_length + 2;
    while (a)
    {
        moves = find_best_move(a, b, a_length, b_length);
        exec_moves(&a, &b, moves);
        a_length--;
        b_length++;
    }
    while (b)
    {
        write(1, "pa\n", 3);
        push(&a, &b);
    }
}

int main(int argc, char **argv)
{
    int a_length;
    t_stack *main_stack;
    t_stack *temp;
    
    a_length = 0;
    main_stack = make_stack(argc, argv);
    if (main_stack)
    {
        temp = main_stack;
        while (temp)
        {
            a_length++;
            temp = temp->next;
        }
        push_swap(a_length, 0, main_stack, NULL);
    }
}
