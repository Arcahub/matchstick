/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfflag
*/

#include "my_printf.h"
#include <stdlib.h>

void print_address(va_list list, char *args, params_t *pms)
{
    long long n = va_arg(list, long long);
    char *str = my_nbr_base_to_str(n, "0123456789abcdef");

    my_putstr("0x");
    my_putstr(str);
    free(args);
    free(pms);
}