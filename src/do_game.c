/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** do_game
*/

#include <sys/socket.h>
#include <unistd.h>
#include "matchstick.h"

void your_turn(game_t *game)
{
    my_printf("\nYour turn:\n");
    read_player_move_and_update_board_game(game);
    if (game->end != -1)
        return;
    for (int i = 0; game->map[i] != '\0'; i++)
        write(1, &game->map[i], 1);
    if (check_end(game)) {
        my_printf("You lost, too bad...\n");
        game->end = 2;
        return;
    }
}

void other_turn(game_t *game)
{
    vector_t vector = {0, 0};

    my_printf("\nOther player's turn...\n");
    if((recv(game->him, &vector, sizeof vector, 0)) < 0) {
        game->end = 84;
        return;
    }
    update_game_board_second(vector.line, vector.matches, game->map, game);
    for (int i = 0; game->map[i] != '\0'; i++)
        write(1, &game->map[i], 1);
    if (check_end(game)) {
        my_printf("Well Played you win!!\n");
        game->end = 1;
        return;
    }
}

void do_game(game_t *game)
{
    if (game->him == game->you) {
        your_turn(game);
        other_turn(game);
    } else {
        other_turn(game);
        your_turn(game);
    }
}