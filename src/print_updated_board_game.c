/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** print_updated_game_board
*/

#include <unistd.h>

void update_game_board(int line, int nb_matches, char *board)
{
    int count = 0;

    my_printf("Player removed %d match(es) from line %d\n", nb_matches, line);
    for (int i = 0; board[i] != '\0'; i++) {
        if (i / 10 == line && board[i] == '|')
            count++;
    }
    count -= nb_matches;
    for (int i = 0; board[i] != '\0'; i++) {
        if (board[i] != '|' || i / 10 != line)
            continue;
        else if (count > 0) {
            count--;
            continue;
        } else
            board[i] = ' ';
    }
}