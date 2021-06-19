#include <stdlib.h>

int is_sep(char c, char *charset)
{
    if (!charset)
        return (1);
    while (*charset)
        if (c == *(charset++))
            return (1);
    return (0);
}

int count_word(char *str, char *charset)
{
    char    **res;
    char    tmp;
    int n;

    n = 0;
    if (!str[0])
        return (0);
    if (!charset || !charset[0])
        return (1);
    tmp = charset[0];
    while (*str)
    {
        if (!is_sep(*str, charset) && is_sep(tmp, charset))
        {
            tmp = *str;
            n++;
        }
        else if (is_sep(*str, charset))
            tmp = *str;
        str++;
    }
    return (n);
}

char    **malloc_res(char *str, char *charset)
{
    int n;
    int i;
    int k;
    char    **res;

    res = malloc(sizeof(char *) * (count_word(str, charset) + 1));
    if (!res)
        return (NULL);
    i = 0;
    k = 0;
    while (i < count_word(str, charset))
    {
        n = 0;
        while (str[k] && is_sep(str[k], charset))
            k++;
        while (str[k] && !is_sep(str[k], charset) && ++n)
            k++;
        res[i] = malloc(sizeof(char) * (n + 1));
        if (!res[i++])
            return (NULL);
    }
    return (res);
}

char    **ft_split(char *str,char *charset)
{
    char    **res;
    int i;
    int j;
    int k;

    if (!str)
        return (NULL);
    res = malloc_res(str, charset);
    if (!res)
        return (NULL);
    i = 0;
    k = 0; 
    while (i < count_word(str, charset))
    {
        j = 0;
        while (str[k] && is_sep(str[k], charset))
            k++;
        while (str[k] && !is_sep(str[k], charset))
            res[i][j++] = str[k++];
        res[i][j] = '\0';
        i++;
    }
    res[i] = NULL;
    return (res);
}
