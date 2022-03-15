/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** test_returnvalues
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dowels.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_return_val, valid_args, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "6", "4", "10", "8", "20", "19", "11", "5", "17"};
    
    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(test_return_val, valid_args2, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "6", "4", "10", "18", "20", "19", "11", "5", "7"};
    
    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(test_return_val, valid_args3, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "4", "5", "13", "19", "20", "16", "12", "7", "4"};
    
    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(test_return_val, valid_args4, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "0", "100", "0", "0", "0", "0", "0", "0", "0"};
    
    cr_assert_eq(start(ac, av), SUCCESS);
}