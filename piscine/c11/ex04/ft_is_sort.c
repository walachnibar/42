# define ASCENDING 0
# define DESCENDING 1

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    int direction;
    int i;

    if (length <= 1 || !tab)
        return (1);
    i = 0;
    while(i < length - 1 && f(tab[i], tab[i + 1]) == 0)
        i++;
    if (f(tab[i], tab[i + 1]) <= 0)
        direction = ASCENDING;
    else
        direction = DESCENDING;
    i = 0;
    while (i < length - 1)
    {
        if ((direction == ASCENDING && f(tab[i], tab[i + 1]) > 0)
            || (direction == DESCENDING && f(tab[i], tab[i + 1]) < 0))
            return (0);
        i++;
    }
    return (1);
}
