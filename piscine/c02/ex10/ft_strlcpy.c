int             ft_strlen(char *str)
{
    int res;

    res = 0;
    while (*(str++))
        res++;
    return (res);
}

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i;

    if (!dest || !src)
        return (ft_strlen(src));
    i = 0;
    while (i < size - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}
