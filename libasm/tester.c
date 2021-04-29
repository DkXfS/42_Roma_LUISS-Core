#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_strcpy(char *dst, const char *src);
int     ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

int main ()
{
    char *std_res;
    char *ft_res;

    std_res = (char *)malloc(10);
    ft_res = (char *)malloc(10);

    printf("STRLEN: %lu \nFT_STRLEN: %d\n", strlen("ciaooooo"), ft_strlen("ciaooooo"));
    printf("\nSTRCPY: %s \nFT_STRCPY: %s\n", strcpy(std_res, "ciaozoko"), ft_strcpy(ft_res, "ciaozoko"));
    printf("\nSTRCMP: %d \nFT_STRCMP: %d\n", strcmp("ciaooooo", "ciaooooo"), ft_strcmp("ciaooooo", "ciaooooo"));
    printf("\nWRITE: %ld\n", write(1, "CIAAO", 5));
    printf("\nFT_WRITE: %ld\n", ft_write(1, "CIAzAO", 6));
}