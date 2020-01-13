/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr_base
*/

#include "my_printf.h"
#include "stdlib.h"

static unsigned long long int my_cpt_pow(unsigned long long int nb, int p)
{
    unsigned long long int result;

    if (p == 0) {
        return 1;
    }
    result = my_cpt_pow(nb, p - 1) * nb;
    return (result);
}

int compute_base(unsigned long long int n, int base_int)
{
    int i = 0;

    for (; my_cpt_pow(base_int, i) < n; i++);
    return (i - 1);
}

char convert_in_base(int len, char const *base, int base_int, \
unsigned long long int *n)
{
    int i = 0;
    unsigned long long int pow = my_cpt_pow(base_int, len);

    for (; *n >= i * pow; i++);
    i -= 1;
    *n -= pow * i;
    return (base[i]);
}

char *my_nbr_base_to_str(unsigned long long int n, char const *base)
{
    int base_int = my_strlen(base);
    int len = 0;
    int len_bis = 0;
    char *nbr = NULL;

    len = compute_base(n, base_int);
    len_bis = len;
    nbr = malloc(sizeof(char) * (len + 2));
    for (int j = 0; len + 1 > 0; len--, j++)
        nbr[j] = (convert_in_base(len, base, base_int, &n));
    nbr[len_bis + 1] = '\0';
    return (nbr);
}