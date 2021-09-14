#include "header.h"

int main()
{
    struct timeval cur_time;
    gettimeofday(&cur_time, NULL);
    printf("seconds : %ld\tmicrosecond : %d\n", cur_time.tv_sec, cur_time.tv_usec);
}