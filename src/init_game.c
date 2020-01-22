/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** init_game
*/

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

void init_game(game_t *game, int nbr_line, int max_matches) {
    game->map = malloc(sizeof(char) * ((nbr_line + 2) * (nbr_line * 2 + 2) + 1));
    if (game->map == NULL) {
        game->end = 84;
        return;
    }
    game->map[(nbr_line + 2) * (nbr_line * 2 + 2)] = '\0';
    game->max_line = nbr_line;
    game->matches_per_turn = max_matches;
    game->map_width = (nbr_line * 2 + 2);
    game->array = malloc(sizeof(int) * game->max_line);
    fillmap(nbr_line, game->map, game->array);
}