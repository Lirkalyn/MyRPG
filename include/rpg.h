/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

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

typedef struct health_s
{
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    sfIntRect rect;
} health_t;

typedef struct mn_sta_s
{
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    sfIntRect rect;
} mn_sta_t;

typedef struct ui_s
{
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    sfIntRect rect;
} ui_t;

typedef struct b_player_s
{
    int nb;
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    sfIntRect rect;
    int pv;
    int atq;
    int exp;
    int lv;
} b_player_t;

typedef struct b_enem_s
{
    int nb;
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
    sfIntRect rect;
    int pv;
    int atq;
} b_enem_t;

typedef struct btl_s
{
    window_t *w;
    player_t **p;
    background_t bck;
    health_t hp;
    mn_sta_t sta;
    ui_t b_ui;
    b_player_t *b_pla;
    b_enem_t *b_ene;
} btl_t;

int find_the_word(char *str, char *find);
int main_game();
int start_duel(window_t *w, player_t **p);
int in_error_disp(int opt, int error);
void *po_error_disp(int opt);
int myputstr(char *str, int opt);
btl_t *batl_init(window_t *w, player_t **p);
sfVector2f posing(int x, int y, sfVector2f pos);
sfIntRect set_rect(int *info, sfIntRect rect);
btl_t *b_ui_init(btl_t *batl);
btl_t *b_player_init(btl_t *batl , int nb);
btl_t *b_enem_init(btl_t *batl, int nb);

#endif