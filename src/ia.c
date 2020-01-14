/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia
*/

#include "matchstick.h"
#include <time.h>
#include <stdlib.h>

int nim_sum(int *array, int max_line)
{
    int first = (array[0] ^ array[1]);
    int second = (array[0] | array[1]);

    for (int i = 2; i < max_line; i++) {
        first = (first ^ array[i]);
        second = (second | array[i]);
    }
    first = first == 0;
    second = second == 1;
    return (first ^ second);
}

void remove_one(game_t *game)
{
    int row = 0;

    srand(time(NULL));
    row = rand() % 4;
    while (game->array[row] == 0)
        row = row % 4 + 1;
    game->array[row] -= 1;
    update_game_board_ia(row + 1, 1, game->map, game);

}

void compute_remove(game_t *game)
{
    int row = 0;
    int tmp = 0;

    srand(time(NULL));
    while (!nim_sum(game->array, game->max_line)) {
        row = rand() % 4;
        while (game->array[row] == 0)
            row = row % 4 + 1;
        tmp = game->array[row];
        while (!nim_sum(game->array, game->max_line) && game->array[row] != 0)
            game->array[row] -= 1;
        if (!nim_sum(game->array, game->max_line))
            game->array[row] = tmp;
    }
    update_game_board_ia(row + 1, tmp - game->array[row], game->map, game);
}

void ia_turn(game_t *game)
{
    if (nim_sum(game->array, game->max_line))
        remove_one(game);
    else
        compute_remove(game);
}