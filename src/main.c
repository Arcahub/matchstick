/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

int matchstick(int nbr_line, int max_matches)
{
    for (int i = 0; i < nbr_line * 2 + 1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0; i < nbr_line; i++) {
        write(1, "*", 1);
        for (int j = 0; j < nbr_line - i - 1; j++)
            write(1, " ", 1);
        for (int j = 0; j < (i * 2) + 1; j++)
            write(1, "|", 1);
        for (int j = 0; j < nbr_line - i - 1; j++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
    for (int i = 0; i < nbr_line * 2 + 1; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    return (1);
}

int main(int argc, char **argv)
{
    int nbr_line = 0;
    int max_matches = 0;

    if (argc != 3)
        return (84);
    nbr_line = (my_getnbr(argv[1]));
    max_matches = (my_getnbr(argv[2]));
    if (nbr_line <= 1 || nbr_line >= 100)
        nbr_line = 4;
    if (max_matches <= 0)
        max_matches = nbr_line;
    return (matchstick(nbr_line, max_matches));
}