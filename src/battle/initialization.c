/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** initialization, initialization everywhere-desu
*/

#include "rpg.h"

sfVector2f posing(int x, int y, sfVector2f pos)
{
    pos.x = x;
    pos.y = y;
    return pos;
}

sfIntRect set_rect(int *info, sfIntRect rect)
{
    rect.height = info[0];
    rect.width = info[1];
    rect.left = info[2];
    rect.top = info[3];
    return rect;
}

btl_t *hp_init(btl_t *batl)
{
    batl->hp.texture = sfTexture_createFromFile("./pict/hp.png", NULL); // 378 * 37
    batl->hp.sprite = sfSprite_create();
    sfSprite_setTexture(batl->hp.sprite, batl->hp.texture, sfTrue);
    batl->hp.pos = posing(450, 625, batl->hp.pos);
    sfSprite_setPosition(batl->hp.sprite, batl->hp.pos);
    batl->hp.rect.height = 37;
    batl->hp.rect.width = ((378 / 20) * batl->b_pla[0].pv);
    batl->hp.rect.left = 0;
    batl->hp.rect.top = 0;
    sfSprite_setTextureRect(batl->hp.sprite, batl->hp.rect);
    sfSprite_setScale(batl->hp.sprite, (sfVector2f){0.75, 0.75});
    return batl;
}

btl_t *sta_init(btl_t *batl)
{
    batl->sta.texture = sfTexture_createFromFile("./pict/mn_sta.png", NULL); // 488 * 96
    batl->sta.sprite = sfSprite_create();
    sfSprite_setTexture(batl->sta.sprite, batl->sta.texture, sfTrue);
    batl->sta.pos = posing(800, 625, batl->sta.pos);
    sfSprite_setPosition(batl->sta.sprite, batl->sta.pos);
    batl->sta.rect.height = 96;
    batl->sta.rect.width = (((488 / 10) * batl->b_pla[0].sta) + 7);
    batl->sta.rect.left = 0;
    batl->sta.rect.top = 0;
    sfSprite_setTextureRect(batl->sta.sprite, batl->sta.rect);
    sfSprite_setScale(batl->sta.sprite, (sfVector2f){0.5, 0.3});
    return batl;
}

btl_t *batl_init(window_t *w, player_t **p)
{
    btl_t *batl = malloc(sizeof(btl_t));
    sfVector2f pos = posing(0, 0, pos);
    srand(rand());

    if (batl == NULL)
        return NULL;
//
    batl->phase = 0;
    batl->p = p;
    batl->w = w;
    batl->bck.texture = sfTexture_createFromFile("./pict/batl_bck2.jpg", NULL);
    batl->bck.sprite = sfSprite_create();
    sfSprite_setTexture(batl->bck.sprite, batl->bck.texture, sfTrue);
//
    batl = b_ui_init(batl);
    batl = b_player_init(batl, 1);
    batl = hp_init(batl);
    batl = sta_init(batl);
    batl = b_base_txt_init(batl, 0);
    batl = b_comp_txt_init(batl, 1);
    batl = b_arrow_init(batl);
    batl = b_enem_init(batl, (1 + (rand() % 3)));
    return batl;
}