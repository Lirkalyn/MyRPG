/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MY_H_
#define MY_H_

#define EXIT_FAIL 84

typedef struct window_s
{
    sfRenderWindow* window;
    sfEvent event;
}window_t;

typedef struct background_s
{
    sfTexture* texture;
    sfSprite* sprite;
    int pos_x;
    int pos_y;
}background_t;

typedef struct player_s
{
    sfTexture* texture;
    sfSprite* sprite;
    int pos_x;
    int pos_y;
}player_t;

typedef struct pnj_s
{
    sfTexture* texture;
    sfSprite* sprite;
    int pos_x;
    int pos_y;
    int num_dialogue;
}pnj_t;

int find_the_word(char *str, char *find);
int main_game();
void start_duel(window_t *w, player_t **p);

#endif /* !MY_H_ */