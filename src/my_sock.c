/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_sock
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include "matchstick.h"

void close_sock(game_t *game)
{
    if (game->him != game->you)
        close(game->him);
    close(game->you);
}

int bind_sock(int sock)
{
    struct sockaddr_in sin = {0};

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(4242);
    if(bind(sock, (struct sockaddr *) &sin, sizeof(sin)) == -1)
        return (84);
    return (0);
}

void init_server(game_t *game)
{
    struct sockaddr_in csin = { 0 };
    int sinsize = sizeof csin;

    if (bind_sock(game->you) == 84) {
        game->end = 84;
        return;
    }
    if (listen(game->you, 5) == -1) {
        game->end = 84;
        return;
    }
    game->him = accept(game->you, (struct sockaddr *)&csin, &sinsize);
    if(game->him == -1) {
        game->end = 84;
        return;
    }
    if (send(game->him, &(vector_t) {game->max_line, game->matches_per_turn}, \
    sizeof(vector_t), 0) < 0)
        game->end = 84;
}

int init_client(game_t *game, char *host)
{
    struct hostent *hostinfo = NULL;
    struct sockaddr_in sin = {0};
    vector_t vector = {0, 0};

    hostinfo = gethostbyname(host);
    if (hostinfo == NULL)
        return (84);
    sin.sin_addr = *(struct in_addr *)hostinfo->h_addr_list[0];
    sin.sin_port = htons(4242);
    sin.sin_family = AF_INET;
    if (connect(game->you, (struct sockaddr *) &sin, \
    sizeof(struct sockaddr)) == -1)
        return (84);
    game->him = game->you;
    if((recv(game->him, &vector, sizeof vector, 0)) < 0)
        game->end = 84;
    else
        init_game(game, vector.line, vector.matches);
    return (game->end);
}

void create_sock(game_t *game, char *host)
{
    game->you = socket(AF_INET, SOCK_STREAM, 0);

    if (game->you == -1) {
        game->end = 84;
        return;
    }
    if (host[0] == '-' && host[1] == 'h')
        init_server(game);
    else
        init_client(game, host);
}