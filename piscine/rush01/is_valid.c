int is_valid(char c, int map_size)
{
    if (c >= '1' && c <= map_size + 48)
        return (1);
    return (0);
}