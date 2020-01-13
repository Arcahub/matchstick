/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putstr_sized
*/

#include "my_printf.h"

void my_putstr_sized(char *str, int n)
{
    for (int i = 0; i < n; i++)
        if (str[i] > 31 && str[i] < 126)
        my_putchar(str[i]);
}