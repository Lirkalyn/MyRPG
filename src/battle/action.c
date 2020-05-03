/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** handling the action-desu
*/

#include "rpg.h"

choice_t *action_mallocer(choice_t *actions)
{
    actions = malloc(sizeof(choice_t));
    if (actions == NULL)
        return NULL;
    actions->id = 0;
    actions->opt = 0;
    actions->target = 0;
    actions->next = NULL;
    actions->previews = NULL;
    return actions;
}

choice_t *action_writer(choice_t *actions, arrow_t arrow)
{
    actions = action_mallocer(actions);
    actions->id = arrow.id;
    actions->opt = arrow.opt;
    actions->target = arrow.target;
    return actions;
}

void menu_1(btl_t *batl)
{
    if (batl->arrow.opt == 0 && batl->phase != 2)
        batl->phase = 2;
    if (batl->arrow.opt == 0 && batl->phase == 2)
        batl->b_ene[batl->arrow.target].pv -= batl->b_pla->atq;
    if (batl->arrow.opt == 1);
        batl->def = 1;
    if (batl->arrow.opt == 2)
        batl->phase = 1;
    if (batl->arrow.opt == 3);
        if (batl->bravely < 4)
            batl->bravely += 1;
    if (batl->arrow.opt == 4);
    if (batl->arrow.opt == 5);
    if (batl->arrow.opt == 6)
        batl->over = 1;
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