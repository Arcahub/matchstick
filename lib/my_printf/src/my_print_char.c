/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_char
*/

#include "my_printf.h"
#include <stdlib.h>

void print_char(va_list list, char *args, params_t *pms)
{
    int c = va_arg(list, int);

    if (pms->pad != '-')
        print_pad(args, 1, pms->pad_val);
    my_putchar(c);
    if (pms->pad == '-')
        print_pad(args, 1, pms->pad_val);
    free(args);
    free(pms);
}