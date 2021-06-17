int     ft_is_lowercase(char c)
{
    if (c < 'a' || c > 'z')
        return (0);
    return (1);
}

char    *ft_strupcase(char *str)
{
    if (!str)
        return (str); 
    while (*(str++))
        if (ft_is_lowercase(*(str - 1)))
            *(str - 1) -= 32;
    return (str);
}