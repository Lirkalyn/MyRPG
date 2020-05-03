/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** here initialize the gauge-desu
*/

#include "rpg.h"

btl_t *hp_init(btl_t *batl)
{
    batl->hp.texture = sfTexture_createFromFile("./pict/hp.png", NULL);
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
    batl->sta.texture = sfTexture_createFromFile("./pict/mn_sta.png", NULL);
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