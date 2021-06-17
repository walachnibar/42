#include <limits.h>

int     atoi(char *str)
{
    int res;
    int neg;

    neg = 0;
    res = 0;
    while (*str && (*str == ' ' || *str == '\t'))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            neg = 1;
        str++;
    }
    while (*str && (*str >= '0' && *str <= '9'))
    {
        res = (res * 10) + (*str - 48);
        str++;
    }
    if (neg)
        return (-res);
    return res;
}

int     main(int argc, char **argv)
{
    printf("%d\n", atoi("           -2147483648"));
    return (0);
}

