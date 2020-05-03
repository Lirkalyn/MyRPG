/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** for error-desu
*/

#include "rpg.h"

int in_error_disp(int opt, int error)
{
    if (opt == 0)
        myputstr("error in the malloc of batl", 0);
    return error;
}

void *po_error_disp(int opt)
{
    if (opt == 0)
        myputstr("error in the malloc of batl", 0);
    if (opt == 1)
        myputstr("error in the malloc of base char *", 0);
    if (opt == 2)
        myputstr("error in the malloc of base next", 0);
    if (opt == 3)
        myputstr("error in menu_txt, we are too far", 0);
    return NULL;
}