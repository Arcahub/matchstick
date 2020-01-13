/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_nbr
*/

#include "my_printf.h"
#include <stdlib.h>

void print_nbr(va_list list, char *args, params_t *pms)
{
    long long int n = get_int_with_length(list, pms);
    char *str = my_nbr_to_str(n);

    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    else if (pms->acc == -1)
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putnbr_sized(str, pms->acc, pms);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}