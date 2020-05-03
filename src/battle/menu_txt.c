/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** to handle the menu-desu
*/

#include "rpg.h"

txt_t *rewinder(txt_t *menu)
{
    while (menu->previews != NULL)
        menu = menu->previews;
    return menu;
}