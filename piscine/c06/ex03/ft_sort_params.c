#include <unistd.h>

void    print_param(char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
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

void    ft_swap_str(char **s1, char **s2)
{
    char    *tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int main(int ac, char **av)
{
    int sorted;
    int i;

    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (++i < ac - 1)
        {
            if (ft_strcmp(av[i], av[i + 1]) > 0)
            {
                ft_swap_str(&av[i], &av[i + 1]);
                sorted = 0;
            }
        }
    }
    while (ac-- > 1)
        print_param(*(++av));
    return (0);
}
