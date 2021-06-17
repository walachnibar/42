void    ft_putchar(char c);

void    rush01(int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            if ((j == 0 && i == 0) || (j == x - 1 && i == y - 1))
                ft_putchar('/');
            else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
                ft_putchar('\\');
            else if (j == 0 || j == x - 1 || i == 0 || i == y - 1)
                ft_putchar('*');
            else
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}