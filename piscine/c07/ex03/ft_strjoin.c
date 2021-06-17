#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int n;

    if (!str)
        return (0);
    n = 0;
    while (*(str++))
        n++;
    return (n);
}

char    *malloc_res(int size, char **strs, char *sep)
{
    char    *res;
    int count;
    int i;

    if (size < 0 || !strs)
        return (NULL);
    if (!size)
    {
        res = malloc(sizeof(char) * 1);
        if (!res)
            return (NULL);
        res[0] = '\0';
        return (res);
    }
    count = 0;
    i = 0;
    while (i < size)
        count += ft_strlen(strs[i++]);
    res = malloc(sizeof(char) * (count + 1 + (size - 1) * ft_strlen(sep)));
    return (res);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *res;
    int i;
    int j;
    int k;

    res = malloc_res(size, strs, sep);
    if (!res)
        return (NULL);
    if (!size)
        return (res);
    k = 0;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
            res[k++] = strs[i][j++];
        if (i + 1 != size && sep)
        {
            j = 0;
            while (sep[j])
                res[k++] = sep[j++];
        }
        i++;
    }
    res[k] = '\0';
    return (res);
}
