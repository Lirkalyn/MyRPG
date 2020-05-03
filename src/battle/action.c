/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** handling the action-desu
*/

#include "rpg.h"

void menu_1(btl_t *batl)
{

}

void menu_2(btl_t *batl)
{

}

void which_menu(btl_t *batl)
{
    if (batl->arrow.id == 0)
        menu_1(batl);
    else if (batl->arrow.id == 1)
        menu_2(batl);
}