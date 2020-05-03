/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** It's time t-t-to to Duel-desu
*/

#include "rpg.h"

btl_t *phaser(int opt, btl_t *batl)
{
    if (batl->phase == 0)
        batl->arrow = base_move(opt, batl->arrow, batl->base);
    if (batl->phase == 1)
        batl->arrow = comp_move(opt, batl->arrow, batl->comp);
    if (batl->phase == 2)
        batl->arrow = enem_move(opt, batl->arrow, batl->b_ene);
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
            if (sfKeyboard_isKeyPressed(sfKeyBack))
                batl->phase = 1;
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
    if (batl->b_pla[0].sta > 0)
        sfRenderWindow_drawSprite(batl->w->window, batl->sta.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->b_pla[0].sprite, NULL);
    for (int i = 0; i < max; i++)
        if (batl->b_ene->pv > 0)
            sfRenderWindow_drawSprite(batl->w->window, batl->b_ene[i].sprite, NULL);
    disp_which_menu(batl);
    sfRenderWindow_drawSprite(batl->w->window, batl->arrow.sprite, NULL);
    sfRenderWindow_display(batl->w->window);
}

int start_duel(window_t *w, player_t **p)
{
    btl_t *batl = batl_init(w, p);
//    int over = 0;

    if (batl == NULL)
        return in_error_disp(0, 85);
    while (sfRenderWindow_isOpen(batl->w->window) && batl->over == 0) {
        sfRenderWindow_setKeyRepeatEnabled(batl->w->window, sfFalse);
        draw(batl);
        if (batl->phase == 0)
            batl->base = rewinder(batl->base);
        else if (batl->phase == 1)
            batl->comp = rewinder(batl->comp);
        b_event(batl->w, batl->p[0], batl);
    }
}