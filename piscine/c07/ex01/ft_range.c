#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *res;
    int i;

    if (min >= max)
        return (NULL);
    res = malloc(sizeof(int) * (max - min - 1));
    if (!res)
        return (NULL);
    i = 0;
    while (++min < max)
        res[i++] = min;
    return (res);
}
