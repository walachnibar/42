int ft_any(char **tab, int (*f)(char*))
{
    if (!tab)
        return (0);
    while (*tab)
        if (f(*(tab++)))
            return (1);
    return (0);
}
