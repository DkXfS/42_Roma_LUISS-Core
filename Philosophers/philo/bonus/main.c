#include "header.h"

int main(int argc, char **argv)
{
    pid_t *pid;
    int i;
    sem_t forks;
    t_main common;

    if (argc < 5)
		printf("ERROR: Not enough arguments\n");
	else if (argc > 6)
		printf("ERROR: Too many arguments\n");
	else
    {
        while (i < common.ph_num)
        {
            pid[i] = fork();
            if (!pid[i])
                //philo_loop
        }
        waitpid(pid[i], )
    }
}