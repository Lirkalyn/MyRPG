/*
** EPITECH PROJECT, 2020
** main_game.c
** File description:
** main_game.c
*/

#include "rpg.h"

void event(window_t *w, player_t *p)
{
    while (sfRenderWindow_pollEvent(w->window, &w->event)) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        p->pos_x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        p->pos_x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        p->pos_y -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        p->pos_y += 1;
}

void destroy_all(window_t *w, background_t *b, player_t *p)
{
    sfRenderWindow_destroy(w->window);
    sfTexture_destroy(b->texture);
    sfSprite_destroy(b->sprite);
    sfTexture_destroy(p->texture);
    sfSprite_destroy(p->sprite);
}

void limit_of_map(player_t *p, background_t *b)
{
    if (p->pos_x > 1450 && b->pos_x > -1300) {
        p->pos_x = 1450;
        b->pos_x -= 1;
    }
    if (p->pos_x < 0 && b->pos_x < 0) {
        p->pos_x = 0;
        b->pos_x += 1;
    }
    if (p->pos_x > 1600)
        p->pos_x = 1600;
    if (p->pos_x < 0)
        p->pos_x = 0;
    if (p->pos_y < 0)
        p->pos_y = 0;
    if (p->pos_y > 750)
        p->pos_y = 750;
}

void create_tex_sprit(background_t *b, player_t *p)
{
    b->texture = sfTexture_createFromFile("./pict/1.png", NULL);
    b->sprite = sfSprite_create();
    sfSprite_setTexture(b->sprite, b->texture, sfTrue);
    b->pos_x = 0;
    b->pos_y = 0;
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
        event(w, p);
        limit_of_map(p, b);
        sfSprite_setPosition(b->sprite, (sfVector2f){b->pos_x, b->pos_y});
        sfRenderWindow_drawSprite(w->window, b->sprite, NULL);
        sfSprite_setPosition(p->sprite, (sfVector2f){p->pos_x, p->pos_y});
        sfRenderWindow_drawSprite(w->window, p->sprite, NULL);
        sfRenderWindow_display(w->window);
    }
    destroy_all(w, b, p);
    return (EXIT_SUCCESS);
}