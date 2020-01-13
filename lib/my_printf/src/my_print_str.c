/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_str
*/

#include "my_printf.h"
#include <stdlib.h>

void print_str(va_list list, char *args, params_t *pms)
{
    char *str = va_arg(list, char *);

    if (pms->acc > my_strlen(str))
        pms->acc = my_strlen(str);
    else if (pms->acc == -1)
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putstr_sized(str, pms->acc);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}

void print_str_full(va_list list, char *args, params_t *pms)
{
    char *str = va_arg(list, char *);

    my_putstrfull(str);
    free(args);
    free(pms);
}