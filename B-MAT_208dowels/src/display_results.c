/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** display_results
*/

#include <stdio.h>
#include "dowels.h"

static void display_first_line(dowels_t *dow)
{
    int tmp = 0;
    int old = 0;
    int i = 0;

    printf("   x\t| ");
    for (i = 0; i < dow->length - 2; ++i, tmp = 0) {
        printf("%d", i);
        tmp = dow->values[i];
        if (tmp < 10) {
            while (tmp < 10 && i < 8)
                tmp = tmp + dow->values[++i];
            if (old != i)
                printf("-%d", i);
        } else
            if (i < dow->length - 2 && dow->values[i+1] < 10 &&
            dow->values[i+2] > dow->values[i]) {
                tmp = tmp + dow->values[++i];
                printf("-%d", i);
            }
        old = i;
        printf("\t| ");
    }
    printf("%d+\t| ", i);
    printf("Total\n");
}

static void display_second_line(dowels_t *dow)
{
    int tmp = 0;

    printf("  Ox\t| ");
    for (int i = 0; i < dow->length; ++i, tmp = 0) {
        tmp = dow->values[i];
        if (tmp < 10)
            while (tmp < 10 && i < 8)
                tmp = tmp + dow->values[++i];
        else
            if (i < dow->length - 2 && dow->values[i+1] < 10 &&
            dow->values[i+2] > dow->values[i])
                tmp = tmp + dow->values[++i];
        printf("%d\t| ", tmp);
    }
    printf("%.0f\n", dow->n);
}

static void display_third_line(dowels_t *dow)
{
    int tmp = 0;
    double theo = 0;

    printf("  Tx\t| ");
    for (int i = 0; i < dow->length; ++i, tmp = 0, theo = 0) {
        tmp = dow->values[i];
        theo = dow->theo[i];
        if (tmp < 10)
            while (tmp < 10 && i < 8) {
                tmp = tmp + dow->values[++i];
                theo += dow->theo[i];
            }
        else
            if (i < dow->length - 2 && dow->values[i+1] < 10 &&
            dow->values[i+2] > dow->values[i]) {
                tmp = tmp + dow->values[++i];
                theo += dow->theo[i];
            }
        printf("%.1f\t| ", theo);
    }
    printf("%.0f\n", dow->n);
}

static void display_fit(dowels_t *dow)
{
    bool printed = false;

    printf("Fit validity:\t\t");
    for (int i = 0; i != 13; i++) {
        if (dow->x < distribution_table[(int)dow->freedom].corr[i]) {
            if (i == 0) {
                printf("P > %.0f%%\n", distribution_table[0].corr[i]);
                printed = true;
                break;
            }
            printf("%.0f%% < P < %.0f%%\n", distribution_table[0].corr[i], distribution_table[0].corr[i - 1]);
            printed = true;
            break;
        }
    }
    if (!printed)
        printf("P < %.0f%%\n", distribution_table[0].corr[12]);
}

void display_results(dowels_t *dow)
{
    display_first_line(dow);
    display_second_line(dow);
    display_third_line(dow);
    printf("Distribution:\t\tB(%.0f, %.4f)\n", dow->n, dow->p);
    printf("Chi-squared:\t\t%.3f\n", dow->x);
    printf("Degrees of freedom:\t%.0f\n", dow->freedom);
    display_fit(dow);
}