/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** intialize the player-desu
*/

#include "rpg.h"

static int *rect(int pos, int *re)
{
    if (pos == 0) {
        re[0] = 44;
        re[1] = 43;
        re[2] = 3;
        re[3] = 23;
        return re;
    }
    return NULL;
}

btl_t *b_player_value_init(btl_t *batl, int i)
{
    batl->b_pla[i].atq = 1;
    batl->b_pla[i].exp = 0;
    batl->b_pla[i].lv = 1;
    batl->b_pla[i].pv = 20;
    batl->b_pla[i].sta = 3;
    return batl;
}

btl_t *b_player_init(btl_t *batl, int nb)
{
    int i = 0;
    int re[4] = {[0 ... 3] = 0};
    sfTexture* tmp;

    batl->b_pla = malloc(nb * sizeof(b_player_t));
    for (; i < nb; i++) {
        batl->b_pla[i].nb = nb;
        tmp = sfTexture_createFromFile("./pict/p0.png", NULL);
        batl->b_pla[i].texture = tmp;
        batl->b_pla[i].sprite = sfSprite_create();
        sfSprite_setTexture(batl->b_pla[i].sprite, tmp, sfTrue);
        batl->b_pla[i].pos = posing(50, 350, batl->b_pla[i].pos);
        sfSprite_setPosition(batl->b_pla[i].sprite, batl->b_pla[i].pos);
        batl = b_player_value_init(batl, i);
        batl->b_pla[i].rect = set_rect(rect(i, re), batl->b_pla[i].rect);
        sfSprite_setTextureRect(batl->b_pla[i].sprite, batl->b_pla[i].rect);
        sfSprite_setScale(batl->b_pla[i].sprite, (sfVector2f){2.5, 2.5});
    }
    return batl;
}