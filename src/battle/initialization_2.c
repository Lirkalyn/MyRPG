/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** more-desu
*/

#include "rpg.h"

btl_t *b_ui_init(btl_t *batl)
{
    batl->b_ui.texture = sfTexture_createFromFile("./pict/UI.png", NULL);
    batl->b_ui.sprite = sfSprite_create();
    sfSprite_setTexture(batl->b_ui.sprite, batl->b_ui.texture, sfTrue);
    batl->b_ui.pos = posing(160, 600, batl->b_ui.pos);
    sfSprite_setPosition(batl->b_ui.sprite, batl->b_ui.pos);
    return batl;
}

btl_t *b_arrow_init(btl_t *batl)
{
    batl->arrow.texture = sfTexture_createFromFile("./pict/arrow.png", NULL);
    batl->arrow.sprite = sfSprite_create();
    sfSprite_setTexture(batl->arrow.sprite, batl->arrow.texture, sfTrue);
    batl->arrow.pos.x = (batl->base->pos.x - 5);
    batl->arrow.pos.y = (batl->base->pos.y + 25);
    batl->arrow.id = batl->base->id;
    batl->arrow.opt = batl->base->opt;
    sfSprite_setPosition(batl->arrow.sprite, batl->arrow.pos);
    sfSprite_setScale(batl->arrow.sprite, (sfVector2f){0.5, 0.5});
    sfSprite_rotate(batl->arrow.sprite, 135.0);
    return batl;
}