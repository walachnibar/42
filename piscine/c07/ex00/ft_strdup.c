#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
    int i;
    char    *res;

    if (!src)
        return (NULL);
    i = 0;
    while (src[i])
        i++;
    res = malloc(sizeof(char) * i + 1);
    if (!res)
        return (NULL);
    i = -1;
    while (src[++i])
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}