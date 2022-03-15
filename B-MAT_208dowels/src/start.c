/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** start
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dowels.h"

static int display_help(char *prog)
{
    printf("USAGE\n");
    printf("    %s O0 O1 O2 O3 O4 O5 O6 O7 O8\n\n", prog);
    printf("DESCRIPTION\n");
    printf("    0i\tsize of the observed class\n");
    return SUCCESS;
}

static void fill_struct(dowels_t *dow, int ac, char **av)
{
    dow->length = 0;
    for (int i = 1; i != ac; ++i) {
        dow->values[i - 1] = atoi(av[i]);
        dow->length++;
    }
    dow->n = 100;
    dow->p = 0;
    dow->x = 0;
    dow->freedom = 0;
}

int start(int ac, char **av)
{
    dowels_t dow;

    if (ac == 2 && !strcmp(av[1], "-h"))
        return display_help(av[0]);
    if (error_handling(ac, av))
        return ERROR;
    fill_struct(&dow, ac, av);
    if (dowels(&dow))
        return ERROR;
    return SUCCESS;
}