void    ft_foreach(int *tab,int length, void (*f)(int))
{
    while (length--)
        f(*(tab++));
}
