/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_base
*/

#include "my_printf.h"
#include <stdlib.h>

void print_octal(va_list list, char *args, params_t *pms)
{
    unsigned long long int n = get_int_unsigned_with_length(list, pms);
    char *str = my_nbr_base_to_str(n, "01234567");

    if (pms->before == '#' && n != 0 && pms->acc <= my_strlen(str))
        my_putstr("0");
    if (n == 0 && pms->acc == 0)
        return;
    else if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    if (pms->pad != '-') {
        print_pad(args, pms->acc, pms->pad_val);
        my_putnbr_sized(str , pms->acc, pms);
    } else if (pms->pad == '-') {
        print_pad(args, pms->acc, pms->pad_val);
        my_putnbr_sized(str , pms->acc, pms);
    }
    free(args);
    free(pms);
}

void print_deci(va_list list, char *args, params_t *pms)
{
    unsigned long long int n = get_int_unsigned_with_length(list, pms);
    char *str = my_nbr_base_to_str(n, "0123456789");

    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putnbr_sized(str, pms->acc, pms);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}

void print_hexa(va_list list, char *args, params_t *pms)
{
    unsigned long long int n = get_int_unsigned_with_length(list, pms);
    char *str = my_nbr_base_to_str(n, "0123456789abcdef");

    if (pms->before == '#' && n != 0)
        my_putstr("0x");
    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putnbr_sized(str, pms->acc, pms);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}

void print_hexa_cap(va_list list, char *args, params_t *pms)
{
    unsigned long long int n = get_int_unsigned_with_length(list, pms);
    char *str = my_nbr_base_to_str(n, "0123456789ABCDEF");

    if (pms->before == '#' && n != 0)
        my_putstr("0X");
    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putnbr_sized(str, pms->acc, pms);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}

void print_binairy(va_list list, char *args, params_t *pms)
{
    unsigned long long int n = get_int_unsigned_with_length(list, pms);
    char *str = my_nbr_base_to_str(n, "01");

    if (pms->before == '#' && n != 0)
        my_putstr("0b");
    if (n == 0 && pms->acc == 0)
        return;
    if (pms->acc < my_strlen(str))
        pms->acc = my_strlen(str);
    if (pms->pad != '-')
        print_pad(args, pms->acc, pms->pad_val);
    my_putnbr_sized(str, pms->acc, pms);
    if (pms->pad == '-')
        print_pad(args, pms->acc, pms->pad_val);
    free(args);
    free(pms);
}