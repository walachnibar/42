#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *res;
    int i;

    res = malloc(sizeof(int) * (max - min - 1));
    if (!res)
        return (NULL);
    i = 0;
    while (++min < max)
        res[i++] = min;
    return (res);
}

int ft_ultimate_range(int **range,int min,int max)
{
    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    *range = ft_range(min, max);
    if (!range)
        return (-1);
    return (max - min - 1);
}
