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
    int matches_per_turn;
    int end;
    int *array;
    int you;
    int him;
    bool is_host;
} game_t;

typedef struct vector
{
    int line;
    int matches;
} vector_t;

void read_player_move_and_update_board_game(game_t *);
void update_game_board_player(int, int, char *, game_t *);
void update_game_board_ia(int, int, char *, game_t *);
void my_printf(char *, ...);
void ia_turn(game_t *game);
#endif /* !MATCHSTICK_H_ */
