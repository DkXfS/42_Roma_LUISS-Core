#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dst, const char *src);
int     ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);

int main ()
{
    char *std_res;
    char *ft_res;

    std_res = (char *)malloc(10);
    ft_res = (char *)malloc(10);

    printf("STRLEN: %lu \nFT_STRLEN: %d\n", strlen("ciaooooo"), ft_strlen("ciaooooo"));
    printf("\nSTRCPY: %s \nFT_STRCPY: %s\n", strcpy(std_res, "ciaozoko"), ft_strcpy(ft_res, "ciaozoko"));
    printf("\nSTRCMP: %d \nFT_STRCMP: %d\n", strcmp("ciaooooo", "ciaoozoo"), ft_strcmp("ciaooooo", "ciaoozoo"));
}