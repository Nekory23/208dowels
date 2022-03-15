/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dowels.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_error, too_many_args_start, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[] = {"\0", "1", "2"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, too_many_args_err, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[] = {"\0", "1", "2"};

    cr_assert_eq(error_handling(ac, av), true);
}

Test(test_error, too_few_args_start, .init=redirect_all_stdout)
{
    int ac = 8;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, too_few_args_error, .init=redirect_all_stdout)
{
    int ac = 8;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7"};

    cr_assert_eq(error_handling(ac, av), true);
}

Test(test_error, invalid_arg_letters_start, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7", "zeif", "9"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, invalid_arg_letters_error, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7", "zeif", "9"};

    cr_assert_eq(error_handling(ac, av), true);
}

Test(test_error, invalid_args_negative_start, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "-7", "8", "9"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, invalid_args_negative_error, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "-7", "8", "9"};

    cr_assert_eq(error_handling(ac, av), true);
}

Test(test_error, not_equal_to_100_start, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, not_equal_to_100_error, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    cr_assert_eq(error_handling(ac, av), true);
}

Test(test_error, no_error_start, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "6", "4", "10", "8", "20", "19", "11", "5", "17"};

    cr_assert_eq(start(ac, av), SUCCESS);
}

Test(test_error, no_error_error, .init=redirect_all_stdout)
{
    int ac = 10;
    char *av[] = {"\0", "6", "4", "10", "8", "20", "19", "11", "5", "17"};

    cr_assert_eq(error_handling(ac, av), false);
}