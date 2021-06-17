#include <unistd.h>

typedef struct  s_pos
{
    int x;
    int y;
}               t_pos;

t_pos   init_pos(int x, int y)
{
    t_pos   pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

int check_case(int board[10][10], t_pos pos)
{
    t_pos   tmp;

    tmp = init_pos(-1, pos.y);
    while (++tmp.x <= 9)
        if (board[tmp.y][tmp.x] == 1 && tmp.x != pos.x)
            return (0);
    tmp = init_pos(pos.x, pos.y);
    while (++tmp.x <= 9 && --tmp.y >= 0)
        if (board[tmp.y][tmp.x] == 1)
            return (0);
    tmp = init_pos(pos.x, pos.y);
    while (++tmp.x <= 9 && ++tmp.y <= 9)
        if (board[tmp.y][tmp.x] == 1)
            return (0);
    tmp = init_pos(pos.x, pos.y);
    while (--tmp.x >= 0 && ++tmp.y <= 9)
        if (board[tmp.y][tmp.x] == 1)
            return (0);
    tmp = init_pos(pos.x, pos.y);
    while (--tmp.x >= 0 && --tmp.y >= 0)
        if (board[tmp.y][tmp.x] == 1)
            return (0);
    return (1);
}

void    print_solution(int board[10][10])
{
    t_pos   pos;
    char    c;

    pos.x = -1;
    while (++pos.x <= 9)
    {
        pos.y = -1;
        while (++pos.y <= 9)
            if (board[pos.y][pos.x] == 1)
            {
                c = pos.y + 48;
                write(1, &c, 1);
            }
    }
    write(1, "\n", 1);
}

void    find_those_fockings_solutions(int board[10][10], t_pos pos, int *n)
{
    while (pos.y <= 9)
    {
        board[pos.y][pos.x] = 1;
        if (check_case(board, pos))
        {
            if (pos.x == 9)
            {
                print_solution(board);
                *n += 1;
            }
            else
                find_those_fockings_solutions(board, init_pos(pos.x + 1, 0), n);
        }
        board[pos.y][pos.x] = 0;
        pos.y++;
    }
}

int ft_ten_queens_puzzle(void)
{
    int n;
    int board[10][10];
    t_pos   pos;

    pos.y = -1;
    while (++pos.y < 10)
    {
        pos.x = -1;
        while (++pos.x < 10)
            board[pos.y][pos.x] = 0;
    }
    pos = init_pos(0, 0);
    n = 0;
    find_those_fockings_solutions(board, pos, &n);
    return (n);
}
