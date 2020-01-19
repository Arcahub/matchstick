/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_float_to_str
*/

#include "my_printf.h"
#include <stdlib.h>

static char digit_to_char(int digits, long double *n)
{
    int digit = 0;
    long double ten = 1;

    for (int d = digits; d > 0; d--) {
        ten = ten * 10;
    }
    for (; *n >= ten; digit++, *n -= ten) {
        if (digit + 48 > '9')
            return (0);
    }
    return (digit + 48);
}

static int get_int_part_length(long double n)
{
    int digits = 0;

    while (n >= 10) {
        digits++;
        n = n / 10;
    }
    return digits;
}

static char *int_part_to_str(long double n, int digits)
{
    char *nbr = NULL;

    if (n < 0)
        n = - n;
    nbr = malloc(sizeof(char) * (digits + 2));
    nbr[digits + 1] = '\0';
    for (int i = 0; digits >= 0; i++, digits--) {
        nbr[i] = digit_to_char(digits, &n);
    }
    return (nbr);
}

static char *add_float_part(char *str, int acc, long double n)
{
    char *float_part = malloc(sizeof(char) * (acc + 2));
    char *result = NULL;

    float_part[0] = '.';
    float_part[acc + 1] = '\0';
    for (int i = 0; i < acc; i++) {
        n *= 10;
        float_part[i + 1] = digit_to_char(0, &n);
    }
    result = my_strcat(str, float_part);
    return (result);
}

char *my_float_to_str(long double n, int acc)
{
    int len = get_int_part_length(n);
    char *str = int_part_to_str(n, len);
    long long int n_int = my_getnbr(str);
    char sign = 0;

    if (n < 0) {
        sign = '-';
        n = - n;
    }
    if (n - n_int != 0)
        str = add_float_part(str, acc, n - n_int);
    if (sign == '-')
        return (my_strcat("-", str));
    return (str);
}
