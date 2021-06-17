#include "const.h"
#include "utils.h"

int check_col(int **map, int map_size)
{
    int i;
    int j;
    int k;

    j = 0;
    while (j < map_size)
    {
        i = 0;
        while (i < map_size)
        {
            if (map[i][j] == 0)
                return (1);
            k = i;
            while (++k < map_size)
                if (map[i][j] == map[k][j])
                    return (0);
            i++;
        }
        j++;
    }
    return (1);
}

int check_row(int **map, int map_size)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < map_size)
    {
        j = 0;
        while (j < map_size)
        {
            if (map[i][j] == 0)
                return (1);
            k = j;
            while (++k < map_size)
                if (map[i][j] == map[i][k])
                    return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_col_up(int **map, int map_size, int **params)
{
    int i;
    int j;
    int comp;
    int count;

    j = 0;
    while (j < map_size)
    {
        /*
        if (map[0][j] != map_size && params[COL_UP][j] == 1)
                return (0);
        if (map[0][j] != 1 && params[COL_UP][j] == map_size)
            return (0);
        */
        comp = 0;
        count = 0;
        i = 0;
        while (i < map_size)
        {
            if (map[i][j] > comp)
            {
                count++;
                comp = map[i][j];
            }
            if (map[i][j] == 0 && count <= params[COL_UP][j])
                return (1);
            i++;
        }
        if (params[COL_UP][j] != count)
            return (0);
        j++;
    }
    return (1);
}

int check_col_down(int **map, int map_size, int **params)
{
    int i;
    int j;
    int comp;
    int count;

    j = 0;
    while (j < map_size)
    {
        comp = 0;
        count = 0;
        i = map_size - 1;
        while (i >= 0)
        {
            if (map[i][j] > comp)
            {
                count++;
                comp = map[i][j];
            }
            if (map[i][j] == 0 && count <= params[COL_DOWN][j])
                return (1);
            i--;
        }
        if (params[COL_DOWN][j] != count)
            return (0);
        j++;
    }
    return (1);
}

int check_row_left(int **map, int map_size, int **params)
{
    int i;
    int j;
    int comp;
    int count;

    i = 0;
    while (i < map_size)
    {
        /*
        if (map[i][0] != map_size && params[ROW_LEFT][i] == 1)
                return (0);
        if (map[i][0] != 1 && params[ROW_LEFT][i] == map_size)
            return (0);
        */
        comp = 0;
        count = 0;
        j = 0;
        while (j < map_size)
        {
            if (map[i][j] > comp)
            {
                count++;
                comp = map[i][j];
            }
            if (map[i][j] == 0 && count <= params[ROW_LEFT][i])
                return (1);
            j++;
        }
        if (params[ROW_LEFT][i] != count)
            return (0);
        i++;
    }
    return (1);
}

int check_row_right(int **map, int map_size, int **params)
{
    int i;
    int j;
    int comp;
    int count;

    i = 0;
    while (i < map_size)
    {
        comp = 0;
        count = 0;
        j = map_size - 1;
        while (j >= 0)
        {
            if (map[i][j] > comp)
            {
                count++;
                comp = map[i][j];
            }
            if (map[i][j] == 0 && count <= params[ROW_RIGHT][i])
                return (1);
            j--;
        }
        if (params[ROW_RIGHT][i] != count)
            return (0);
        i++;
    }
    return (1);
}

int check_map(int **map, int map_size, int **params, t_pos pos)
{
    if (!check_col(map, map_size) || !check_row(map, map_size)
        || !check_col_up(map, map_size, params)
        || !check_row_left(map, map_size, params))
        return (0);
    if (pos.x == map_size - 1 && pos.y == map_size - 1
        && (!check_col_down(map, map_size, params)
        || !check_row_right(map, map_size, params)))
        return (0);
    else if (pos.x == map_size - 1
        && !check_row_right(map, map_size, params))
        return (0);
    else if (pos.y == map_size - 1
        && !check_col_down(map, map_size, params))
        return (0);
    return (1);
}