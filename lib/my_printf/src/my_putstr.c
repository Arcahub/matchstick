/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** print string
*/

#include "my_printf.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 31 && str[i] < 126)
            my_putchar(str[i]);
        i++;
    }
}