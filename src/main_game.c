/*
** EPITECH PROJECT, 2020
** main_game.c
** File description:
** main_game.c
*/

#include "rpg.h"

void event(window_t *w)
{
    while (sfRenderWindow_pollEvent(w->window, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->window);
    }
}

void destroy_all(window_t *w, background_t *b, player_t *p)
{
    sfRenderWindow_destroy(w->window);
    sfTexture_destroy(b->texture);
    sfSprite_destroy(b->sprite);
    sfTexture_destroy(p->texture);
    sfSprite_destroy(p->sprite);
}

void create_tex_sprit(background_t *b, player_t *p)
{
    b->texture = sfTexture_createFromFile("./pict/1.png", NULL);
    b->sprite = sfSprite_create();
    sfSprite_setTexture(b->sprite, b->texture, sfTrue);
    p->texture = sfTexture_createFromFile("./pict/player.png", NULL);
    p->sprite = sfSprite_create();
    sfSprite_setTexture(p->sprite, p->texture, sfTrue);
    sfSprite_setScale(p->sprite, (sfVector2f){0.15, 0.15});
    p->pos_x = 200;
    p->pos_y = 375;
}

int main_game()
{
    window_t *w = malloc(sizeof(window_t));
    background_t *b = malloc(sizeof(background_t));
    player_t *p = malloc(sizeof(player_t));
    sfVideoMode mode = {1700, 850, 32};

    w->window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    if (!w->window)
        return EXIT_FAIL;
    create_tex_sprit(b, p);
    while (sfRenderWindow_isOpen(w->window)) {
        event(w);
        sfRenderWindow_drawSprite(w->window, b->sprite, NULL);
        sfSprite_setPosition(p->sprite, (sfVector2f){p->pos_x, p->pos_y});
        sfRenderWindow_drawSprite(w->window, p->sprite, NULL);
        sfRenderWindow_display(w->window);
    }
    destroy_all(w, b, p);
    return (EXIT_SUCCESS);
}