/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** mystrdup
*/

#include "my_printf.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int length;
    char *str;

    length = my_strlen(src);
    str = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i <= length; i++)
    {
        str[i] = src[i];
    }
    return (str);
}