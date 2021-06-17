int ft_str_is_printable(char *str)
{
    if (!str || !*str)
        return (1); 
    while (*(str++))
        if (*(str - 1) < 32)
            return (0);
    return (1);
}