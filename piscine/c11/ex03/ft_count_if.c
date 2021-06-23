int ft_count_if(char **tab, int length, int (*f)(char*))
{
    int res;
    int i;

    if (!tab)
        return (0);
    res = 0;
    i = 0;
    while (i < length && tab[i])
        if (f(tab[i++]))
            res++;
    return (res);
}