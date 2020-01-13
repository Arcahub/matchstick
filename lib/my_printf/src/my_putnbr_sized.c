/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr_sized
*/

#include "my_printf.h"

void my_putnbr_sized(char *str, int size, params_t *pms)
{
    int len = my_strlen(str);
    int i = 0;

    if (str[0] == '-') {
        i++;
        my_putchar(str[0]);
    } else if (pms->sign == '+' || pms->sign == ' ')
        my_putchar(pms->sign);
    if (size > len)
        for (int i = 0; i < size - len; i++)
            my_putchar('0');
    for (; i < len; i++)
        my_putchar(str[i]);
}