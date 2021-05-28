#include "header.h"

t_moves together_forw(t_moves moves)
{
    while (moves.ra && moves.rb)
    {
        moves.rr++;
        moves.ra--;
        moves.rb--;
    }
    moves.total = moves.ra + moves.rb + moves.rr;
    return (moves);
}

t_moves together_rev(t_moves moves, int a_length, int b_length)
{
    moves.rra = a_length - moves.ra;
    moves.rrb = b_length - moves.rb;
    moves.ra = 0;
    moves.rb = 0;
    while (moves.rra && moves.rrb)
    {
        moves.rrr++;
        moves.rra--;
        moves.rrb--;
    }
    moves.total = moves.rra + moves.rrb + moves.rrr;
    return (moves);
}

t_moves together_case(t_moves moves, int a_length, int b_length)
{
    t_moves rev;
    t_moves forw;

    rev = together_rev(moves, a_length, b_length);
    forw = together_forw(moves);
    if (rev.total < forw.total)
        return (rev);
    else
        return (forw);
}

t_moves separate_case(t_moves moves, int a_length, int b_length)
{
    if (moves.ra > (a_length / 2))
    {
        moves.rra = a_length - moves.ra;
        moves.ra = 0;
    }
    if (moves.rb > (b_length / 2))
    {
        moves.rrb = b_length - moves.rb;
        moves.rb = 0;
    }
    moves.total = moves.ra + moves.rra + moves.rb + moves.rrb;
    return (moves);
}

t_moves optimize(t_moves moves, int a_length, int b_length, int ra)
{
    t_moves separate;
    t_moves together;

    moves.ra = ra;
    together = together_case(moves, a_length, b_length);
    separate = separate_case(moves, a_length, b_length);
    if (together.total < separate.total)
        return(together);
    else
        return (separate);
}