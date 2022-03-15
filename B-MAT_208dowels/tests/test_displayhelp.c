/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** test_displayhelp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dowels.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(return_value, display_help, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./209poll", "-h"};

    cr_assert_eq(start(ac, av), SUCCESS);
}