/*
** EPITECH PROJECT, 2021
** B-MAT_208dowels
** File description:
** dowels
*/

#include <stdio.h>
#include <math.h>
#include "dowels.h"

static double factorial(int nbr)
{
    double res = 1;

    if (nbr == 0)
        return res;
    for (int i = 1; i != nbr + 1; ++i)
        res *= i;
    return res;
}

static void compute_distri(dowels_t *dow)
{
    double tempres = 0;
    double res = 0;

    for (int i = 0; i != dow->length; ++i, res = 0) {
        res = factorial(dow->n) / (factorial(i) * factorial(dow->n - i));
        dow->theo[i] = dow->n * res;
        dow->theo[i] *= pow(dow->p, i);
        dow->theo[i] *= pow(1 - dow->p, dow->n - i);
    }
    for (int i = 0; i != dow->length - 1; ++i)
        tempres += dow->theo[i];
    dow->theo[8] = dow->n - tempres;
}

static void compute_chi(dowels_t *dow)
{
    double tmp = 0;
    double theo = 0;

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
        dow->x += pow(tmp - theo, 2) / theo;
    }
}

static int get_len(dowels_t *dow)
{
    int len = 0;
    int tmp = 0;

    for (int i = 0; i < dow->length; ++i, tmp = 0) {
        tmp = dow->values[i];
        if (tmp < 10)
            while (tmp < 10 && i < 8)
                tmp = tmp + dow->values[++i];
        else
            if (i < dow->length - 2 && dow->values[i+1] < 10 &&
            dow->values[i+2] > dow->values[i])
                tmp = tmp + dow->values[++i];
        len++;
    }
    return len;
}

bool dowels(dowels_t *dow)
{
    for (int i = 0; i != dow->length; ++i)
        dow->p += i * dow->values[i];
    dow->p /= dow->n * dow->n;
    compute_distri(dow);
    compute_chi(dow);
    dow->freedom = get_len(dow) - 2;
    display_results(dow);
    return false;
}