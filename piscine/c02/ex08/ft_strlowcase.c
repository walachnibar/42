int     ft_is_uppercase(char c)
{
    if (c < 'A' || c > 'Z')
        return (0);
    return (1);
}

char    *ft_strlowcase(char *str)
{
    if (!str)
        return (str); 
    while (*(str++))
        if (ft_is_uppercase(*(str - 1)))
            *(str - 1) += 32;
    return (str);
}