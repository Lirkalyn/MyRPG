/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** bla-desu
*/

#include "rpg.h"

static int *enem_rect(int *re)
{
    re[0] = 66;
    re[1] = 62;
    re[2] = 13;
    re[3] = 390;
    return re;
}

btl_t *b_enem_init(btl_t *batl , int nb)
{
    int i = 0;
    int re[4] = {[0 ... 3] = 0};
    sfTexture* tmp;

    batl->b_ene = malloc(nb * sizeof(b_enem_t));
    for (; i < nb; i++) {
//
        batl->b_ene[i].nb = nb;
        batl->b_ene[i].id = i;
//
        tmp = sfTexture_createFromFile("./pict/wolf.png", NULL);
        batl->b_ene[i].texture = tmp;
        batl->b_ene[i].sprite = sfSprite_create();
        sfSprite_setTexture(batl->b_ene[i].sprite, tmp, sfTrue);
        batl->b_ene[i].pos = posing((1300 + (50 * i)), (350 + (75 * i)), batl->b_ene[i].pos);
        sfSprite_setPosition(batl->b_ene[i].sprite, batl->b_ene[i].pos);
//
        batl->b_ene[i].atq = (5 + rand() % 10);
        batl->b_ene[i].pv = (15 + rand() % 5);
//
        batl->b_ene[i].rect = set_rect(enem_rect(re), batl->b_ene[i].rect);
        sfSprite_setTextureRect(batl->b_ene[i].sprite, batl->b_ene[i].rect);
        sfSprite_setScale(batl->b_ene[i].sprite, (sfVector2f){1.75, 1.75});
    }
    return batl;
}

btl_t *b_comp_txt_init_2(btl_t *batl)
{
    sfFont *test = sfFont_createFromFile("rsc/Calibri Regular.ttf");

    while (batl->comp->previews != NULL)
        batl->comp = batl->comp->previews;
    while (batl->comp->next != NULL) {
        sfText_setFont(batl->comp->text, test);
        sfText_setCharacterSize(batl->comp->text, 55);
        sfText_setColor(batl->comp->text, sfBlack);
        sfText_setPosition(batl->comp->text, batl->comp->pos);
        batl->comp = batl->comp->next;
    }
    while (batl->comp->previews != NULL)
        batl->comp = batl->comp->previews;
    return batl;
}