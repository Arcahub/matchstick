/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** print_updated_game_board
*/

#include <unistd.h>
#include "matchstick.h"

void update_game_board_player(int line, int nb_matches, char *board, \
game_t *game)
{
    int count = 0;

    game->array[line - 1] -= nb_matches;
    my_printf("Player removed %d match(es) from line %d\n", nb_matches, line);
    for (int i = 0; board[i] != '\0'; i++) {
        if (i / (game->max_line * 2 + 2) == line && board[i] == '|')
            count++;
    }
    count -= nb_matches;
    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] != '|' || i / (game->max_line * 2 + 2) != line)
            continue;
        else if (count > 0) {
            count--;
            continue;
        } else
            board[i] = ' ';
    }
    if (send(game->him, (vector_t) {line, nb_matches}, sizeof(vector_t), 0) < 0)
        game->end = 84;
}

void update_game_board_second(int line, int nb_matches, char *board, \
game_t *game)
{
    int count = 0;

    my_printf("Other player removed %d match(es) from line %d\n", nb_matches, line);
    for (int i = 0; board[i] != '\0'; i++) {
        if (i / (game->max_line * 2 + 2) == line && board[i] == '|')
            count++;
    }
    count -= nb_matches;
    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] != '|' || i / (game->max_line * 2 + 2) != line)
            continue;
        else if (count > 0) {
            count--;
            continue;
        } else
            board[i] = ' ';
    }
}