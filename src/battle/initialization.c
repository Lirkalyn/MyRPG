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
    batl->hp.pos = posing(50, 50, batl->hp.pos);
    sfSprite_setPosition(batl->hp.sprite, batl->hp.pos);
    return batl;
}

btl_t *sta_init(btl_t *batl)
{
    batl->sta.texture = sfTexture_createFromFile("./pict/mn_sta.png", NULL); // 488 * 96
    batl->sta.sprite = sfSprite_create();
    sfSprite_setTexture(batl->sta.sprite, batl->sta.texture, sfTrue);
    batl->sta.pos = posing(100, 100, batl->sta.pos);
    sfSprite_setPosition(batl->sta.sprite, batl->sta.pos);
    return batl;
}

btl_t *batl_init(window_t *w, player_t **p)
{
    btl_t *batl = malloc(sizeof(btl_t));
    sfVector2f pos = posing(0, 0, pos);

    if (batl == NULL)
        return NULL;
    batl->p = p;
    batl->w = w;
    batl->bck.texture = sfTexture_createFromFile("./pict/batl_bck2.jpg", NULL);
    batl->bck.sprite = sfSprite_create();
    sfSprite_setTexture(batl->bck.sprite, batl->bck.texture, sfTrue);
    batl = hp_init(batl);
    batl = sta_init(batl);
    batl = b_ui_init(batl);
    batl = b_player_init(batl, 1);
    return batl;
}