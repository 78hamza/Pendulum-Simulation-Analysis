#include <stdlib.h>

int count_digits(int n)
{
    int count;

    count = 0;
    
    if (n == 0)
        return 1;
    if  (n < 0)
        count++;

    while(n)
    {
        n /= 10;
        count++;
    }
    return count;
}

char    *fill_to(int n, char *str)
{
    int len;
    long    nb;  

    nb = n;
    len = count_digits(n);
    if (n == 0)
        str[0] = '0';
    str[len] = '\0';

    if (n < 0)
    {
        str[0] = '-';
        nb = -nb;
    }    
    while (nb > 0)
    {
        str[--len] = (nb % 10) + 48;
        nb /= 10;
    }

    return (str);
}

char    *ft_itoa(int n)
{
    char    *n_str;
    int len;
    
    len = count_digits(n);
    n_str = malloc(sizeof(char) * (len + 1));
    if (!n_str)
        return NULL;
    fill_to(n, n_str);
    return n_str;
}
