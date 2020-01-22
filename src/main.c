/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "matchstick.h"

int fill_map_matches(int nbr_line, int index, char *map, int *array)
{
    for (int i = 0; i < nbr_line; i++, index++) {
        map[index] = '*';
        index++;
        for (int j = 0; j < nbr_line - i - 1; j++, index++)
            map[index] = ' ';
        for (int j = 0; j < (i * 2) + 1; j++, index++) {
            map[index] = '|';
            array[i]++;
        }
        for (int j = 0; j < nbr_line - i - 1; j++, index++)
            map[index] = ' ';
        map[index] = '*';
        index += 1;
        map[index] = '\n';
    }
    return (index);
}

void fillmap(int nbr_line, char *map, int *array)
{
    int index = 0;

    for (int i = 0; i < nbr_line; i++)
        array[i] = 0;
    for (int i = 0; i < nbr_line * 2 + 1; i++, index++)
        map[index] = '*';
    map[index] = '\n';
    index++;
    index = fill_map_matches(nbr_line, index, map, array);
    for (int i = 0; i < nbr_line * 2 + 1; i++, index++)
        map[index] = '*';
    map[index] = '\n';
}

int check_end(game_t *game)
{
    int result = 0;

    for (int i = 0; game->map[i] != '\0'; i++)
        if (game->map[i] == '|')
            result++;
    return (!result);
}

int matchstick(int nbr_line, int max_matches, char *host)
{
    game_t game = {NULL, 0, 0, 0, 0, -1, NULL, 0, 0, false};

    create_sock(&game, host);
    if (game.end == 84)
        return (84);
    game.map = malloc(sizeof(char) * ((nbr_line + 2) * (nbr_line * 2 + 2) + 1));
    if (game.map == NULL)
        return (84);
    game.map[(nbr_line + 2) * (nbr_line * 2 + 2)] = '\0';
    game.max_line = nbr_line;
    game.matches_per_turn = max_matches;
    game.map_width = (nbr_line * 2 + 2);
    game.array = malloc(sizeof(int) * game.max_line);
    fillmap(nbr_line, game.map, game.array);
    while (game.end == -1) {
        do_game(&game);
    }
    return (game.end);
}

int main(int argc, char **argv)
{
    int nbr_line = 0;
    int max_matches = 0;

    if (argc != 4)
        return (84);
    nbr_line = (my_getnbr(argv[1]));
    max_matches = (my_getnbr(argv[2]));
    if (nbr_line <= 1 || nbr_line >= 100)
        nbr_line = 4;
    if (max_matches <= 0)
        max_matches = nbr_line;
    return (matchstick(nbr_line, max_matches, argv[3]));
}