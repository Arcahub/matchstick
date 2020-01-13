/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdbool.h>
#include "get_next_line.h"
#include "my.h"

typedef struct game {
    char *map;
    int max_line;
    int map_width;
    int max_matches;
    int end;
} game_t;

void read_player_move_and_print_updated_board_game(game_t *);
void print_updated_game_board(int, int, char *);
void my_printf(char *, ...);
#endif /* !MATCHSTICK_H_ */
