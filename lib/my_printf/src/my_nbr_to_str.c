/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** print all digits
*/

#include "my_printf.h"
#include <stdlib.h>

static char *display_nbr(long long n, int digits)
{
    long long int digit = 0;
    long long int ten = 1;
    int print = 0;
    char *nbr = NULL;

    nbr = malloc(sizeof(char) * (digits + 2));
    nbr[digits + 1] = '\0';
    for (int i = 0; digits >= 0; i++) {
        for (int d = digits; d > 0; d--) {
            ten = ten * 10;
        }
        digit = (n / ten);
        n = n - (digit * ten);
        print = digit + 48;
        nbr[i] = print;
        ten = 1;
        digits--;
    }
    return (nbr);
}

static long long int get_int_length(long long int n)
{
    long long int digits = 0;

    while (n >= 10) {
        digits++;
        n = n / 10;
    }
    return digits;
}

char *my_nbr_to_str(long long int n)
{
    long long int digits = 0;
    char sign = '+';
    char *str = NULL;

    if (n < 0) {
        sign = '-';
        n = - n;
    }
    digits = get_int_length(n);
    str = (display_nbr(n, digits));
    if (sign == '-')
        return (my_strcat("-", str));
    return (str);
}