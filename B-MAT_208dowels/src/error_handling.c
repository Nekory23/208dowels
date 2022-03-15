/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** error_handling
*/

#include <stdlib.h>
#include <stdio.h>
#include "dowels.h"

bool error_handling(int ac, char **av)
{
    int check = 0;

    if (ac != 10) {
        fprintf(stderr, "This program takes 9 arguments\n");
        return true;
    }
    for (int i = 1; i != ac; ++i)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9') {
                fprintf(stderr, "All the arguments must be integers\n");
                return true;
            }
    for (int i = 1; i != ac; ++i)
        check += atoi(av[i]);
    if (check != 100) {
        fprintf(stderr, "The sum of the args must be 100\n");
        return true;
    }
    return false;
}