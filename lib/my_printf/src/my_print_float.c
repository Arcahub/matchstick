/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_float
*/

#include "my_printf.h"
#include <stdlib.h>

void print_float(va_list list, char *args, params_t *pms)
{
    long double n = get_float_with_length(list, pms);
    char *str = NULL;

    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc == -1 || pms->acc > 6)
        pms->acc = 6;
    str = my_float_to_str(n, pms->acc);
    pms->acc = my_strlen(str);
    if (pms->pad != '-') {
        print_pad(args, pms->acc, pms->pad_val);
        my_putstr(str);
    } else if (pms->pad == '-') {
        my_putstr(str);
        print_pad(args, pms->acc, pms->pad_val);
    }
    free(args);
    free(pms);
}