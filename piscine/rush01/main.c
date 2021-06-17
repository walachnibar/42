#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "utils.h"

void    ft_putchar(char c);
void    ft_putstr(char *str);
int     is_valid(char c, int map_size);

t_pos   init_pos(int x, int y)
{
    t_pos   pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

int     error()
{
    ft_putstr("Error\n");
    return (1);
}

int     error_msg(char *msg)
{
    error();
    ft_putstr(msg);
    ft_putstr("\n");
    return (1);
}

void    print_params(int **params, int map_size)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < map_size)
            printf("%d ", params[i][j]);
        printf("\n");
    }
}

void    print_map(int **map, int map_size)
{
    int i;
    int j;

    i = -1;
    while (++i < map_size)
    {
        j = -1;
        while (++j < map_size)
        {
            ft_putchar(map[i][j] + 48);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

int     get_map_size(char *param)
{
    int count;
    int i;

    if (!param)
        return (0);
    count = 0;
    i = 0;
    while (param[i])
    {
        if (!(i % 2))
            count++;
        i++;
    }
    if (count % 4)
        return (0);
    return (count / 4);
}

int     **malloc_params(int map_size)
{
    int     i;
    int    **params;

    if (!(params = malloc(sizeof(int *) * 4)))
            return (NULL);
    i = 0;
    while (i < 4)
    {
        if (!(params[i] = malloc(sizeof(int) * map_size)))
            return (NULL);
        i++;
    }
    return (params);
}

int     **parse(char *param, int map_size)
{
    int     i;
    int     j;
    int     k;
    int    **params;

    if (!(params = malloc_params(map_size)))
        return (NULL);
    k = 0;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < map_size)
        {
            if (!is_valid(param[k], map_size))
                return (NULL);
            params[i][j] = param[k] - 48;
            k += 2;
            j++;
        }
        i++;
    }
    return (params);
}

int     **inst_map(int map_size)
{
    int **map;
    int i;
    int j;
    
    if (!(map = malloc(sizeof(int *) * map_size)))
        return (NULL);
    i = -1;
    while (++i < map_size)
        if (!(map[i] = malloc(sizeof(int) * map_size)))
            return (NULL);
    i = -1;
    while (++i < map_size)
    {
        j = -1;
        while (++j < map_size)
            map[i][j] = 0;
    }
    return (map);
}

int     search_map(int **map, int map_size, int **params, t_pos pos)
{
    int i;

    i = 1;
    while (i <= map_size)
    {
        //print_map(map, map_size);
        map[pos.y][pos.x] = i;
        if (check_map(map, map_size, params, pos))
        {
            if (pos.x == map_size - 1 && pos.y == map_size - 1)
                return (1);
            if (pos.x == map_size - 1)
                pos = init_pos(0, pos.y + 1);
            else
                pos = init_pos(pos.x + 1, pos.y);
            if (search_map(map, map_size, params, pos))
                return (1);
            if (pos.x == 0 && pos.y != 0)
                pos = init_pos(map_size - 1, pos.y - 1);
            else
                pos = init_pos(pos.x - 1, pos.y);
        }
        i++;
        //printf("\n");
    }
    map[pos.y][pos.x] = 0; 
    return (0);
}

int     main(int ac, char **av)
{
    int map_size;
    int **params;
    int **map;
    int map_tmp[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int i;
    int j;
    t_pos   pos;

    if (ac != 2)
        return (error_msg("argc != 2"));
    if (!(map_size = get_map_size(av[1])))
        return (error_msg("map size"));
    if (!(params = parse(av[1], map_size)))
        return (error_msg("parsing"));
    if (!(map = inst_map(map_size)))
        return (error_msg("inst map"));

    /*
    //PUT VALUE IN MAP
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            map[i][j] = map_tmp[i][j];
            j++;
        }
        i++;
    }
    */

    printf("map_size: %d\n", map_size);
    print_params(params, map_size);
    printf("\n\n");

    //printf("check_map: %d\n", check_map(map, map_size, params));
    //printf("check_row: %d\n", check_row(map, map_size));
    
    pos = init_pos(0, 0);
    if (search_map(map, map_size, params, pos))
        print_map(map, map_size);
    else
        error_msg("No solutions");


    printf("\n\n");
    printf("Keep working boi\n");
    return (0);
}

/*

    ### Solved input ###

4 : 3 1 3 2 1 4 2 2 2 3 2 1 2 1 2 3
5 : 3 4 1 2 2 3 2 4 1 2 2 3 1 2 3 3 1 5 3 2
6 : 4 3 3 1 2 2 1 3 3 2 2 3 4 3 2 2 4 1 3 1 3 2 2 4
7 : 1 4 2 4 3 3 2 2 2 4 3 3 1 3 1 4 3 3 4 2 2 3 1 3 2 3 2 2
4 : 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2

*/