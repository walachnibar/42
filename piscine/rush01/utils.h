#ifndef UTILS
#define UTILS

typedef struct  s_pos
{
    int x;
    int y;
}               t_pos;

int check_row(int **map, int map_size);
int check_map(int **map, int map_size, int **params, t_pos pos);
int check_col_up(int **map, int size_map, int **params);
int check_col_down(int **map, int map_size, int **params);
int check_row_right(int **map, int map_size, int **params);
int check_row_left(int **map, int map_size, int **params);

#endif