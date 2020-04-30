/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** It's time t-t-to to Duel-desu
*/

#include "rpg.h"

static void b_event(window_t *w, player_t *p)
{
    while (sfRenderWindow_pollEvent(w->window, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->window);
    }
}

void draw(btl_t *batl)
{
    sfRenderWindow_clear(batl->w->window, sfBlack);
    sfRenderWindow_drawSprite(batl->w->window, batl->bck.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->b_ui.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->hp.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->sta.sprite, NULL);
    sfRenderWindow_drawSprite(batl->w->window, batl->b_pla[0].sprite, NULL);
    sfRenderWindow_display(batl->w->window);
}

int start_duel(window_t *w, player_t **p)
{
    btl_t *batl = batl_init(w, p);
    int over = 0;

    if (batl == NULL)
        return in_error_disp(0, 85);
    while (sfRenderWindow_isOpen(batl->w->window) && over == 0) {
        draw(batl);
        b_event(batl->w, batl->p[0]);
    }
}