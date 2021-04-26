#include "header.h"

void    exit_all(char *err, void *to_free)
{
    printf("%s", err);
    to_free = 0;          //  ???
    exit(0);
}

void    check_ascension(t_stack *a)
{
    t_stack *temp = a;

    while(temp)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
    while (a->next)
    {
        if(a->num >= a->next->num)
            exit_all("KO\n", a);
        a = a->next;
    }
    printf("OK\n");
}

void    arrange(t_stack *a)
{
    command_route(&a, NULL, NULL);
    check_ascension(a);
}

int     check_dupe(t_stack *a)
{
    int val;

    val = a->num;
    a = a->next;
    while (a)
    {
        if (a->num == val)
            return (1);
        a = a->next;
    }
    return (0);
}

int     main(int argc, char **argv)
{
    t_stack *a;
    t_stack *temp;

    if (argc < 2)
        printf("ERROR\nNo parameters found\n");
    else
    {
        temp = NULL;
        while (argc-- > 1)
        {
            if (!(a = (t_stack *)malloc(sizeof(t_stack))))
                exit_all("ERROR\nMemAlloc Failed\n", a);
            a->next = temp;
            if (temp)
                temp->prev = a;
            if (*(argv[argc]) < '0' || *(argv[argc]) > '9')
                exit_all("ERROR\nInvalid Parameters\n", a);
            a->num = *(argv[argc]) - '0';
            temp = a;
            if (check_dupe(a))
                exit_all("ERROR\nDuplicate values inserted\n", a);
            a = a->prev;
        }
        a = NULL;
        a = temp;
        arrange(a);
    }
}