/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** read_player_move_and_print_updated_board_game
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "matchstick.h"

static int sign_nbr(int nbr, int sign)
{
    int divide_int = sign % 2;

    if (divide_int == 0) {
        return (nbr);
    }
    nbr = - nbr;
    return (nbr);
}

int my_getnbr(char const *str)
{
    int sign = 0;
    int nbr = 0;
    int v = 0;

    for (int i = 0; str[i] != '\0' && v == 0; i++) {
        if (str[i] == '-')
            sign++;
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - 48;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
            v = 1;
    }
    return (sign_nbr(nbr, sign));
}

int get_matches(game_t *game, int line)
{
    int matches = 0;
    int max_matches = 0;
    int i = game->map_width * line;
    char *input = NULL;

    for (; game->map[i] != '\n' && game->map[i] != '\0'; i++)
        if (game->map[i] == '|')
            max_matches++;
    game->max_matches = max_matches;
    write(1, "Matches: ", 10);
    input = get_next_line(0);
    if (input == NULL) {
        game->end = true;
        return (84);
    }
    matches = my_getnbr(input);
    if (matches <= 0)
        write(1, "Error: you have to remove at least one match\n", 45);
    else if (matches > max_matches)
        write(1, "Error: not enough matches on this line\n", 39);
    return (matches);
}

void read_player_move_and_print_updated_board_game(game_t *game)
{
    int line = 0;
    int matches = 0;
    char *input = NULL;

    while ((line <= 0 || line > game->max_line) && game->end == -1) {
        write(1, "Line: ", 7);
        input = get_next_line(0);
        if (input == NULL) {
            game->end = true;
            return;
        }
        line = my_getnbr(input);
        if (line <= 0 || line > game->max_line)
            write(1, "Error: this line is out of range\n", 33);
        else
            matches = get_matches(game, line);
        if (matches <= 0 || matches > game->max_matches)
            line = 0;

    }
    update_game_board_player(line, matches, game->map, game);
}