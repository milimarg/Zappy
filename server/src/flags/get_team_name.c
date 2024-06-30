/*
** EPITECH PROJECT, 2024
** B-YEP-400-STG-4-1-zappy-augustin.grosnon
** File description:
** get_team_name
*/

#include "server.h"
#include <string.h>

void add_one_team(server_t *server, char *name)
{
    team_t *tmp = server->world.teams;
    team_t *new = smalloc(sizeof(team_t), "get_team_name.c - add_one_team");

    memset(new, 0, sizeof(team_t));
    new->name = strdup(name);
    if (!server->world.teams)
        server->world.teams = new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

char **get_team_name(server_t *server, char **argv)
{
    while (argv[0] && argv[0][0] != '-') {
        add_one_team(server, argv[0]);
        argv++;
    }
    return argv;
}
