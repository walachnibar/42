int     ft_str_is_uppercase(char *str)
{
    if (!str || !*str)
        return (1); 
    while (*(str++))
        if (*(str - 1) < 'A' || *(str - 1) > 'Z')
            return (0);
    return (1);
}