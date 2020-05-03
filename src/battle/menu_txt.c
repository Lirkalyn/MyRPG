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

void disp_which_menu(btl_t *batl)
{
    if (batl->phase == 0)
        while (batl->base->next != NULL) {
            sfRenderWindow_drawText(batl->w->window, batl->base->text, NULL);
            batl->base = batl->base->next;
        }
    else if (batl->phase == 1)
        while (batl->comp->next != NULL) {
            sfRenderWindow_drawText(batl->w->window, batl->comp->text, NULL);
            batl->comp = batl->comp->next;
        }
}

arrow_t base_move(int opt, arrow_t arrow, txt_t *base)
{
    base = rewinder(base);
    if (opt == 0) {
        arrow.opt = ((arrow.opt + 1) >= 7) ? 0 : (arrow.opt + 1);
        while (base->next != NULL && arrow.opt != base->opt)
            base = base->next;
    }
    else if (opt == 1) {
        arrow.opt = ((arrow.opt - 1) < 0) ? 6 : (arrow.opt - 1);
        while (base->next != NULL && arrow.opt != base->opt)
            base = base->next;
    }
    arrow.pos.x = (base->pos.x - 5);
    arrow.pos.y = (base->pos.y + 25);
    arrow.id = base->id;
    arrow.opt = base->opt;
    sfSprite_setPosition(arrow.sprite, arrow.pos);
    base = rewinder(base);
    return arrow;
}

arrow_t comp_move(int opt, arrow_t arrow, txt_t *comp)
{
    comp = rewinder(comp);
    if (opt == 0) {
        arrow.opt = ((arrow.opt + 1) >= 5) ? 0 : (arrow.opt + 1);
        while (comp->next != NULL && arrow.opt != comp->opt)
            comp = comp->next;
    }
    else if (opt == 1) {
        arrow.opt = ((arrow.opt - 1) < 0) ? 4 : (arrow.opt - 1);
        while (comp->next != NULL && arrow.opt != comp->opt)
            comp = comp->next;
    }
    arrow.pos.x = (comp->pos.x - 5);
    arrow.pos.y = (comp->pos.y + 40);
    arrow.id = comp->id;
    arrow.opt = comp->opt;
    sfSprite_setPosition(arrow.sprite, arrow.pos);
    comp = rewinder(comp);
    return arrow;
}

arrow_t enem_move(int opt, arrow_t arrow, b_enem_t *wolf)
{
    if (opt == 0) {
        arrow.target += 1;
        if (arrow.target >= wolf->nb)
            arrow.target = 0;
        while (arrow.target < wolf->nb && (wolf[arrow.target].pv <= 0))
            arrow.target += 1;
    }
    else if (opt == 1) {
        arrow.target -= 1;
        if (arrow.target < 0)
            arrow.target = (wolf->nb - 1);
        while (arrow.target >= 0 && (wolf[arrow.target].pv <= 0))
            arrow.target -= 1;
    }
    arrow.pos.x = (wolf[arrow.target].pos.x - 5);
    arrow.pos.y = (wolf[arrow.target].pos.y + 40);
    arrow.target = arrow.target;
    sfSprite_setPosition(arrow.sprite, arrow.pos);
    return arrow;
}