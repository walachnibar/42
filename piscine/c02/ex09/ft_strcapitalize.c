int     ft_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int     is_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int     ft_is_num(char c)
{
    if (c < '0' || c > '9')
        return (0);
    return (1);
}

int     is_alphanum(char c)
{
    if (ft_is_alpha(c) || ft_is_num(c))
        return (1);
    return (0);
}

char    *ft_strcapitalize(char *str)
{
    char    *tmp;

    if (!str)
        return (str);
    tmp = str;
    while (*tmp)
    {
        if (is_alphanum(*tmp))
        {
            if (is_lowercase(*tmp))
                *tmp -= 32;
            while (is_alphanum(*(++tmp)))
                if (*tmp >= 'A' && *tmp <= 'Z')
                    *tmp += 32;
        }
        else
            tmp++;
    }
    return (str);
}
