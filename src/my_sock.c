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
}

void init_client(game_t *game, char *host)
{
    struct hostent *hostinfo = NULL;
    struct sockaddr_in sin = {0};

    hostinfo = gethostbyname(host);
    if (hostinfo == NULL) {
        game->end = 84;
        return;
    }
    sin.sin_addr = *(struct in_addr *)hostinfo->h_addr_list[0];
    sin.sin_port = htons(4242);
    sin.sin_family = AF_INET;
    if (connect(game->you, (struct sockaddr *) &sin, \
    sizeof(struct sockaddr)) == -1) {
        game->end = 84;
        return;
    }
    game->him = game->you;
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