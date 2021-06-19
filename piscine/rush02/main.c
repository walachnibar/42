/*
    NEED TO...

    .think about parsing and dict errors

    .handle non printable char in parsing

    .handle numbers as same as in atoi, in dict or param or both ?
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define BUFF_SIZE 1024

char    **ft_split(char *str,char *charset);

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int err(void)
{
    ft_putstr("Error\n");
    return (1);
}

void    *err_msg(char *msg)
{
    printf("Error: %s\n", msg);
    return (NULL);
}

int     ft_strlen(char *str)
{
    int n;

    if (!str)
        return (0);
    n = 0;
    while (*(str++))
        n++;
    return (n);
}

char    *add_buff(char **data, char *buff)
{
    int i;
    int j;
    char    *new_data;

    new_data = malloc(sizeof(char) * (ft_strlen(*data) + ft_strlen(buff) + 1));
    if (!new_data)
        return (err_msg("Malloc in add_buff"));
    i = -1;
    while ((*data)[++i])
        new_data[i] = (*data)[i];
    j = -1;
    while (buff[++j])
        new_data[i + j] = buff[j];
    new_data[i + j] = '\0';
    return (new_data);
}

char    *get_data(char *filename)
{
    int i;
    int n;
    int fd;
    char    *data;
    char    buff[BUFF_SIZE];

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (err_msg("Could not open file"));
    data = malloc(sizeof(char) * 1);
    if (!data)
        return (err_msg("Malloc in get_data"));
    *data = '\0';
    n = 1;
    while (n > 0 && data)
    {
        n = read(fd, buff, BUFF_SIZE - 1);
        buff[n] = '\0';
        data = add_buff(&data, buff);
    }
    if (n == -1 || !data)
        return (err_msg("Reading file or add_buff->null"));
    return (data);
}

int count_lines(char *str)
{
    int n;

    n = 0;
    while (*str)
        if (*(str++) == '\n')
            n++;
    return (n);
}

char    **get_dict(char *data)
{
    char    **dict;

    dict = ft_split(data, " :\n");
    return (dict);
}

void    print_dict(char **dict)
{
    int i;

    i = 0;
    while (dict[i])
    {   
        if (!(i % 2))
            printf("%s : ", dict[i]);
        else
            printf("%s\n", dict[i]);
        i++;
    }
}

/*
char    *my_pretty_little_special_atoi(char *param)
{
    int i;
    int neg;
    char    *res;

    neg = 0;
    while (*param && (*param == '\v' || *param == '\n' || *param == '\t'
        || *param == '\r' || *param == '\f' || *param == '\v'))
        param++;
    if (*param == '-' || *param == '+')
    {
        if (*param == '-')
            neg = 1;
        param++;
    }
    i = 0;
    while (param[i] && param[i] >= '0' && param[i] <= '9')
        i++;
}
*/

int check_param(char *param)
{
    int i;

    i = 0;

    while (param[i])
    {
        if (param[i] < '0' || param[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

char    *get_value(char **dict, char *key)
{
    int i;

    i = 0;
    while (dict[i])
    {
        if (!(i % 2) && !ft_strcmp(dict[i], key))
            return (dict[i + 1]);
        i++;
    }
    return (NULL);
}

char    *char_to_str(char c)
{
    char    *res;

    res = malloc(sizeof(char) * 2);
    if (!res)
        return (NULL);
    res[0] = c;
    res[1] = '\0';
    return (res);
}

char    *create_minouscoulous_key(char *nbr)
{
    char    *res;

    res = malloc(sizeof(char) * 3);
    if (!res)
        return (NULL);
    res[0] = *nbr;
    if (*nbr == '1')
        res[1] = *(nbr + 1);
    else
        res[1] = '0';
    res[2] = '\0';
    return (res);
}

char    *create_enormimousgigagocoulous_key(char *nbr)
{
    int i;
    char    *key;

    key = malloc(sizeof(char) * (ft_strlen(nbr) + 1));
    if (!key)
        return (NULL);
    key[0] = '1';
    i = 1;
    while (i < ft_strlen(nbr))
        key[i++] = '0';
    key[i] = '\0';
    return (key);
}

void    print_nbr(char **dict, char *nbr)
{
    int n;

    n = ft_strlen(nbr) % 3;
    ft_putstr(nbr);
    ft_putstr(" : ");
    if (ft_strlen(nbr) == 1 && nbr[0] == '0')
    {
        ft_putstr(get_value(dict, nbr));
        return ;
    }
    if (n)
    {
        if (n == 1)
            ft_putstr(get_value(dict, char_to_str(*nbr)));
        else if (n == 2 && *nbr == '1')
            ft_putstr(get_value(dict, create_minouscoulous_key(nbr)));
        else
        {
            ft_putstr(get_value(dict, create_minouscoulous_key(nbr)));
            ft_putstr(" ");
            ft_putstr(get_value(dict, char_to_str(*(nbr + 1))));
        }
        if (ft_strlen(nbr) > 3)
        {
            ft_putstr(" ");
            ft_putstr(get_value(dict, create_enormimousgigagocoulous_key(nbr + n - 1)));
            ft_putstr(" ");
        }
        else
            return ;
        nbr += n;
    }
    while (*nbr)
    {
        if (*nbr != '0')
        {
            ft_putstr(get_value(dict, char_to_str(*nbr)));
            ft_putstr(" ");
            ft_putstr(get_value(dict, "100"));
            ft_putstr(" ");
        }
        nbr++;
        if (*nbr && *nbr != '0')
            ft_putstr(get_value(dict, create_minouscoulous_key(nbr)));
        nbr++;
        if (*nbr && *nbr != '0' && *(nbr - 1) != '1')
        {
            if (*(nbr - 1) != '0')
                ft_putstr(" ");
            ft_putstr(get_value(dict, char_to_str(*nbr)));
        }
        if (*nbr && *(nbr + 1) && (*nbr != '0' || *(nbr - 1) != '0' || *(nbr - 2) != '0'))
        {
            ft_putstr(" ");
            ft_putstr(get_value(dict, create_enormimousgigagocoulous_key(nbr)));
            ft_putstr(" ");
        }
        nbr++;
    }
}

int main(int ac, char **av)
{
    char    *data;
    char    *filename = "numbers.dict";
    char    **dict;

    if (ac != 2 && ac != 3)
        return (err());
    if (!check_param(av[1]))
        return (err());
    data = get_data(filename);
    dict = get_dict(data);
    print_dict(dict);
    printf("\n");
    print_nbr(dict, av[1]);
    printf("\n\nLet's fcking go boi\n");
    return (0);
}