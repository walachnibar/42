int     ft_str_is_lowercase(char *str)
{
    if (!str || !*str)
        return (1); 
    while (*(str++))
        if (*(str - 1) < 'a' || *(str - 1) > 'z')
            return (0);
    return (1);
}