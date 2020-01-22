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

    if (host[0] == '-' && host[1] == 'h')
        init_game(&game, nbr_line, max_matches);
    create_sock(&game, host);
    if (game.end == 84)
        return (84);
    for (int i = 0; game.map[i] != '\0'; i++)
        write(1, &game.map[i], 1);
    while (game.end == -1)
        do_game(&game);
    close_sock(&game);
    return (game.end);
}

int main(int argc, char **argv)
{
    int nbr_line = 0;
    int max_matches = 0;

    if (argc < 2)
        return (84);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return (matchstick(nbr_line, max_matches, argv[1]));
    else if (argc == 4) {
        nbr_line = (my_getnbr(argv[1]));
        max_matches = (my_getnbr(argv[2]));
        if (nbr_line <= 1 || nbr_line >= 100)
            nbr_line = 4;
        if (max_matches <= 0)
            max_matches = nbr_line;
        return (matchstick(nbr_line, max_matches, argv[3]));
    } else
        return (84);
}