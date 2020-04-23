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

void destroy_all(window_t *w, background_t *b)
{
    sfRenderWindow_destroy(w->window);
    sfTexture_destroy(b->texture);
    sfSprite_destroy(b->sprite);
}

int main_game()
{
    window_t *w = malloc(sizeof(window_t));
    background_t *b = malloc(sizeof(background_t));
    sfVideoMode mode = {1700, 850, 32};

    w->window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    if (!w->window)
        return EXIT_FAIL;
    b->texture = sfTexture_createFromFile("./pict/1.png", NULL);
    b->sprite = sfSprite_create();
    sfSprite_setTexture(b->sprite, b->texture, sfTrue);
    while (sfRenderWindow_isOpen(w->window)) {
        event(w);
        sfRenderWindow_drawSprite(w->window, b->sprite, NULL);
        sfRenderWindow_display(w->window);
    }
    destroy_all(w, b);
    return (EXIT_SUCCESS);
}