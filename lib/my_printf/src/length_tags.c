/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** length_tags
*/

#include "my_printf.h"

long double get_float_with_length(va_list list, params_t *pms)
{
    if (pms->length_float == 'L')
        return (va_arg(list, long double));
    return (va_arg(list, double));
}

unsigned long long int get_int_unsigned_with_length(va_list list, params_t *pms)
{
    switch (pms->length_int) {
        case 'h':
            return ((unsigned short int)va_arg(list, unsigned int));
        case 'l':
            return (va_arg(list, unsigned long int));
        case 'L':
            return (va_arg(list, unsigned long long int));
    }
    return (va_arg(list, unsigned int));
}

long long int get_int_with_length(va_list list, params_t *pms)
{
    switch (pms->length_int) {
        case 'h':
            return ((short int) va_arg(list, int));
        case 'l':
            return (va_arg(list, long int));
        case 'L':
            return (va_arg(list, long long int));
    }
    return (va_arg(list, int));
}

params_t *get_length_tags(char *args, params_t *pms)
{
    for (int i = 0; args[i] != '\0'; i++) {
        if (args[i] == 'h' && pms->length_int == 0)
            pms->length_int = 'h';
        if (args[i] == 'l' && args[i + 1] == 'l')
            pms->length_int = 'L';
        else if (args[i] == 'l' && pms->length_int != 'L')
            pms->length_int = 'l';
        if (args[i] == 'L')
            pms->length_float = 'L';
    }
    return (pms);
}