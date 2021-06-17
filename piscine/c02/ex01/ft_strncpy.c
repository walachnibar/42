#include <stdio.h>

void    print_null(char *s)
{
    while (*(s++))
        printf("%c", *(s - 1));
    printf("\\0\n");
}

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    if (!dest || !src)
        return (NULL);
    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
        dest[i++] = '\0';
    return (dest);
}

int main()
{
    char dest[6] = "lolep";
    char *ptr;

    ptr = ft_strncpy(dest, "mdr c mo", 6);
    print_null(dest);
}