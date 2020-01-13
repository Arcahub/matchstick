/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putstrfull
*/

#include "my_printf.h"
#include <stdlib.h>

char *make_printable(int n)
{
    char *str = my_strdup("/000");
    int pow = 100;

    if (n < 0)
        return (my_strdup(""));
    for (int i = 0; i < 3; i++, pow /= 10) {
        str[i + 1] = (n / pow) + 48;
        n = n - (n / pow) * pow;
    }
    return (str);
}

void my_putstrfull(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            my_putstr(make_printable(str[i]));
        else
            my_putchar(str[i]);
    }
}