/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int check_specifier(char *str, int j, va_list list, void \
(*MYPF[12])(va_list, char *, params_t *))
{
    char *specifiers = "csdiouxXbSpf";
    char *args = NULL;
    params_t *pms = NULL;

    for (int i = 0; specifiers[i] != '\0'; i++) {
        if (str[j] == specifiers[i]) {
            args = malloc(sizeof(char) * (j + 1));
            args = my_strncpy(args, str, j);
            pms = make_params(args);
            pms = get_length_tags(args, pms);
            MYPF[i](list, args, pms);
            return (i);
        }
    }
    return (-1);
}

int convert(char *str, va_list list, void \
(*MYPF[12])(va_list, char *, params_t *))
{
    int c = -1;
    int bool = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.' || str[i] == '*' || (str[i] > 48 && str[i] < 58))
            bool = 1;
        else if (bool == 1 && str[i] == ' ') {
            my_putchar(*(str - 1));
            return (-1);
        }
        c = check_specifier(str, i, list, MYPF);
        if (c != -1)
            return (i);
    }
    return (0);
}

void init_mypf(void (*MYPF[13])(va_list, char *, params_t *))
{
    MYPF[0] = &print_char;
    MYPF[1] = &print_str;
    MYPF[2] = &print_nbr;
    MYPF[3] = &print_nbr;
    MYPF[4] = &print_octal;
    MYPF[5] = &print_deci;
    MYPF[6] = &print_hexa;
    MYPF[7] = &print_hexa_cap;
    MYPF[8] = &print_binairy;
    MYPF[9] = &print_str_full;
    MYPF[10] = &print_address;
    MYPF[11] = &print_float;
    MYPF[12] = 0;
}

void my_printf(char *str, ...)
{
    va_list list;
    void (*MYPF[13])(va_list, char *, params_t *);

    init_mypf(MYPF);
    if (str == NULL)
        exit(84);
    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '%') {
            i++;
            my_putchar(str[i]);
        } else if (str[i] == '%') {
            i++;
            i += convert((str + i), list, MYPF);
        } else
            my_putchar(str[i]);
    }
    va_end(list);
}