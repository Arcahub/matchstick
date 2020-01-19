/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** params
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

params_t *init_params(void)
{
    params_t *pms = NULL;

    pms = malloc(sizeof(params_t));
    pms->pad = 0;
    pms->pad_val = ' ';
    pms->acc = -1;
    pms->before = 0;
    pms->sign = 0;
    pms->output = -1;
    pms->length_char = 0;
    pms->length_int = 0;
    pms->length_float = 0;
    return (pms);
}

char check_sign(char c, char actual)
{
    if (c == '+')
        return ('+');
    else if (c == ' ' && actual != '+')
        return (' ');
    return (0);
}

char check_for_zero(int i, char *args, params_t *pms)
{
    if (args[i] != '0')
        return (pms->pad_val);
    if (pms->acc != -1 || pms->pad == '-')
        return (' ');
    if (pms->pad_val == '0')
        return ('0');
    for (; i >= 0; i--) {
        if (args[i] >= '1' && args[i] <= '9')
            return (' ');
    }
    return ('0');
}

params_t *make_params(char *args)
{
    params_t *pms = NULL;

    pms = init_params();
    for (int i = 0; args[i] != '\0'; i++) {
        switch (args[i]) {
        case '-':
            pms->pad = '-';
            break;
        case '#':
            pms->before = '#';
            break;
        case '.':
            pms->acc = my_getnbr(args + i + 1);
            break;
        case '*':
            return (NULL);
        }
        pms->pad_val = check_for_zero(i, args, pms);
        pms->sign = check_sign(args[i], pms->sign);
    }
    return (pms);
}

void print_pad(char *args, int n, char c)
{
    char *cpystr = NULL;
    int len = 0;
    int i = 0;

    for (; args[i] != '\0'; i++) {
        if (args[i] == '.') {
            cpystr = malloc(sizeof(char) * (i + 1));
            cpystr = my_strncpy(cpystr, args, i);
        }
    }
    if (cpystr == NULL) {
        cpystr = malloc(sizeof(char) * (i + 1));
        cpystr = my_strncpy(cpystr, args, i);
    }
    len = my_getnbr(cpystr);
    if (len < 0)
        len = - len;
    for (int i = 0; i < len - n; i++)
        my_putchar(c);
}