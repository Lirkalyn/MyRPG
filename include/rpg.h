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
    sfRenderWindow *window;
    sfEvent event;
}window_t;

typedef struct background_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int pos_x;
    int pos_y;
}background_t;

typedef struct player_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int pos_x;
    int pos_y;
}player_t;

typedef struct pnj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    int pos_x;
    int pos_y;
    int num_dialogue;
}pnj_t;

typedef struct health_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} health_t;

typedef struct mn_sta_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} mn_sta_t;

typedef struct ui_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} ui_t;

typedef struct b_player_s
{
    int nb;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    int pv;
    int atq;
    int exp;
    int lv;
    int sta;
} b_player_t;

typedef struct b_enem_s
{
    int nb;
    int id;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    int pv;
    int atq;
} b_enem_t;

typedef struct txt_s
{
    sfText *text;
    sfVector2f pos;
    int id;
    int opt;
    struct txt_s *next;
    struct txt_s *previews;
} txt_t;

typedef struct arrow_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int id;
    int opt;
    int target;
} arrow_t;

typedef struct choice_s
{
    int id;
    int opt;
    int target;
    struct choice_s *next;
    struct choice_s *previews;
} choice_t;

typedef struct btl_s
{
    int phase;
    int def;
    int bravely;
    int over;
    window_t *w;
    player_t **p;
    background_t bck;
    health_t hp;
    mn_sta_t sta;
    ui_t b_ui;
    b_player_t *b_pla;
    b_enem_t *b_ene;
    txt_t *base;
    txt_t *comp;
    arrow_t arrow;
    choice_t *actions;
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
btl_t *b_base_txt_init(btl_t *batl, int id);
char *menu_txt(int id, int pos);
btl_t *b_arrow_init(btl_t *batl);
btl_t *b_enem_init(btl_t *batl , int nb);
btl_t *b_comp_txt_init(btl_t *batl, int id);
void which_menu(btl_t *batl);
void menu_1(btl_t *batl);
btl_t *hp_init(btl_t *batl);
btl_t *sta_init(btl_t *batl);
txt_t *rewinder(txt_t *menu);
void disp_which_menu(btl_t *batl);
arrow_t base_move(int opt, arrow_t arrow, txt_t *base);
arrow_t comp_move(int opt, arrow_t arrow, txt_t *comp);
arrow_t enem_move(int opt, arrow_t arrow, b_enem_t *wolf);

#endif