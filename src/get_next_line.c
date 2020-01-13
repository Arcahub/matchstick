/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** getnextline
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int compute_line(char *buffer, int fd)
{
    int i = 0;

    if (fd < 1)
        return (0);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' || buffer[i] == EOF)
            return (i);
    }
    return (i);
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb, int fd)
{
    int length_dest = 0;
    char *result = NULL;

    if (dest != NULL)
        length_dest = my_strlen(dest);
    result = malloc(sizeof(char) * (nb + length_dest + 1));
    if (result == NULL || (nb == 0 && length_dest == 0))
        return (NULL);
    for (int i = 0; i < nb + length_dest + 1; result[i] = '\0', i++);
    if (dest != NULL)
        for (int i = 0; dest[i] != '\0'; result[i] = dest[i], i++);
    for (int i = 0; i <= nb && src[i] != '\0'; i++) {
        if (src[i] == '\n')
            return (result);
        result[length_dest  + i] = src[i];
    }
    return (result);
}

void clear_buffer(char *buffer, int index)
{
    int i = 0;
    int j = 0;

    for (; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        buffer[i] = '\0';
    }
    if (buffer[i] == '\n') {
        buffer[i] = '\0';
        i++;
    }
    for (; buffer[i] != '\0'; i++, j++) {
        buffer[j] = buffer[i];
        buffer[i] = '\0';
    }
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1];
    char *result = NULL;
    int index = 0;
    int size = 0;

    buffer[READ_SIZE] = '\0';
    index = compute_line(buffer, fd);
    result = my_strncat(result, buffer, index, fd);
    for (size = read(fd, buffer, READ_SIZE); size >= READ_SIZE; result = \
    my_strncat(result, buffer, index, fd), size = read(fd, buffer, READ_SIZE)) {
        index = compute_line(buffer, fd);
        if (buffer[index] == '\n' || buffer[index] == EOF) {
            result = my_strncat(result, buffer, index, fd);
            clear_buffer(buffer, index);
            return (result);
        }
    }
    result = my_strncat(result, buffer, size, fd);
    clear_buffer(buffer, size);
    return (result);
}