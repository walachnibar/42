# define SUB 0
# define ADD 1
# define MULTI 2
# define DIV 3
# define MOD 4

void    ft_putstr(char *str);

int div(int x, int y)
{
    if (y == 0)
    {
        ft_putstr("Stop : division by zero\n");
        return (-1);
    }
    return (x / y);
}

int mod(int x, int y)
{
    if (y == 0)
    {
        ft_putstr("Stop : modulo by zero\n");
        return (-1);
    }
    return (x % y);
}

int multi(int x, int y)
{
    return (x * y);
}

int sub(int x, int y)
{
    return (x - y);
}

int add(int x, int y)
{
    return (x + y);
}

int ft_strlen(char *str)
{
    int n;

    n = 0;
    while (*(str++))
        n++;
    return (n);
}

int is_op(char c, char *operators)
{
    return (0);
}

int do_op(int x, int y, int (*op)(int, int))
{
    return (op(x, y));
}

int get_operator(char *param2, char *operators)
{
    if (ft_strlen(param2) != 1 || !is_op(*param2, operators))
    {
        ft_putstr("0\n");
        return (-1);
    }
    if (*param2 == '+')
        return (ADD);
    if (*param2 == '-')
        return (SUB);
    if (*param2 == '*')
        return (MULTI);
    if (*param2 == '/')
        return (DIV);
    return (MOD);
}

int (*p[5]) (int x, int y);

int main(int ac, char **av)
{
    int x;
    int y;
    char    operators[] = "+-/%*";
    int operator;

    if (ac != 4)
        return (1); //err
    operator = get_operator(av[2], operators);
    if (operator == -1)
        return (0);
    x = ft_atoi(av[1]);
    y = ft_atoi(av[3]);
    do_op(x, y, operator);
    return (0);
}