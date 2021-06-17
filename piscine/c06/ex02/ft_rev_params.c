#include <unistd.h>

void    print_param(char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    while (--ac > 0)
        print_param(av[ac]);
    return (0);
}
