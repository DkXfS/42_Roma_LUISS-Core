#include "header.h"

int	ft_atoi(const char *nptr)
{
	int num;
	int minus;

	minus = 1;
	num = 0;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * minus);
}

void    exit_all(char *err, t_stack *to_free)
{
    t_stack *temp;

    write(1, err, ft_strlen(err));
    while (to_free)
    {
        temp = to_free;
        to_free = to_free->next;
        free(temp);
    }
    exit(0);
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

t_stack *make_stack(int argc, char **argv)
{
    t_stack *a;
    t_stack *temp;

    a = NULL;
    if (argc < 2)
        write(1, "ERROR\nNo parameters found\n", 26);
    else
    {
        temp = NULL;
        while (argc-- > 1)
        {
            if (!(a = (t_stack *)malloc(sizeof(t_stack))))
                exit_all("ERROR\nMemAlloc Failed\n", a);
            a->next = temp;
            a->prev = NULL;
            if (temp)
                temp->prev = a;
            if (*(argv[argc]) < '0' || *(argv[argc]) > '9')
                exit_all("ERROR\nInvalid Parameters\n", a);
            a->num = ft_atoi(argv[argc]);
            temp = a;
            if (check_dupe(a))
                exit_all("ERROR\nDuplicate values inserted\n", a);
//            a = a->prev;
        }
//        a = temp;
    }
    return (a);
}