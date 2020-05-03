/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** It's time t-t-to to Duel-desu
*/

#include "rpg.h"

arrow_t base_moove(int opt, arrow_t arrow, txt_t *base)
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

btl_t *phaser(int opt, btl_t *batl)
{
    if (batl->phase == 0)
        batl->arrow = base_moove(opt, batl->arrow, batl->base);
    if (batl->phase == 1)
        batl->arrow = base_moove(opt, batl->arrow, batl->comp);
//    if (batl->phase == 1)
//    if (batl->phase == 2)
    return batl;
}

static void b_event(window_t *w, player_t *p, btl_t *batl)
{
    while (sfRenderWindow_pollEvent(w->window, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->window);
        if (w->event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyUp))
                batl = phaser(1, batl);
            if (sfKeyboard_isKeyPressed(sfKeyLeft))
                batl = phaser(1, batl);
            if (sfKeyboard_isKeyPressed(sfKeyRight))
                batl = phaser(0, batl);
            if (sfKeyboard_isKeyPressed(sfKeyDown))
                batl = phaser(0, batl);
            if (sfKeyboard_isKeyPressed(sfKeySpace))
                which_menu(batl);
//            if (sfKeyboard_isKeyPressed(sfKeyBack))
//                printf("back\n");
        }
    }
}

void draw(btl_t *batl)
{
    int max = batl->b_ene->nb;

    sfRenderWindow_clear(batl->w->window, sfBlack);
    sfRenderWindow_drawSprite(batl->w->window, batl->bck.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->b_ui.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->hp.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->sta.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->b_pla[0].sprite, NULL);
    for (int i = 0; i < max; i++)
        if (batl->b_ene->pv > 0)
            sfRenderWindow_drawSprite(batl->w->window, batl->b_ene[i].sprite, NULL);
    while (batl->base->next != NULL) {
        sfRenderWindow_drawText(batl->w->window, batl->base->text, NULL);
        batl->base = batl->base->next;
    }
/*
    while (batl->comp->next != NULL) {
        sfRenderWindow_drawText(batl->w->window, batl->comp->text, NULL);
        batl->comp = batl->comp->next;
    }
*/
    sfRenderWindow_drawSprite(batl->w->window, batl->arrow.sprite, NULL);
    sfRenderWindow_display(batl->w->window);
}

int start_duel(window_t *w, player_t **p)
{
    btl_t *batl = batl_init(w, p);
    int over = 0;

    if (batl == NULL)
        return in_error_disp(0, 85);
    while (sfRenderWindow_isOpen(batl->w->window) && over == 0) {
        sfRenderWindow_setKeyRepeatEnabled(batl->w->window, sfFalse);
        draw(batl);
        batl->base = rewinder(batl->base);
//        batl->comp = rewinder(batl->comp);
        b_event(batl->w, batl->p[0], batl);
    }
}