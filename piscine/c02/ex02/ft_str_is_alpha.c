int     ft_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int     ft_str_is_alpha(char *str)
{
    if (!str || !*str)
        return (1);
    while (*str)
        if (!ft_is_alpha(*(str++)))
            return (0);
    return (1);
}
