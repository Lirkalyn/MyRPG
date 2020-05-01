/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** more-desu
*/

#include "rpg.h"

btl_t *b_ui_init(btl_t *batl)
{
    batl->b_ui.texture = sfTexture_createFromFile("./pict/UI.png", NULL); // 1380 * 250
    batl->b_ui.sprite = sfSprite_create();
    sfSprite_setTexture(batl->b_ui.sprite, batl->b_ui.texture, sfTrue);
    batl->b_ui.pos = posing(160, 600, batl->b_ui.pos);
    sfSprite_setPosition(batl->b_ui.sprite, batl->b_ui.pos);
    return batl;
}

int *rect(int pos, int *re)
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

btl_t *b_player_init(btl_t *batl , int nb)
{
    int i = 0;
    int re[4] = {[0 ... 3] = 0};
    sfTexture* tmp;

    batl->b_pla = malloc(nb * sizeof(b_player_t));
    for (; i < nb; i++) {
        batl->b_pla[i].nb = nb;
        tmp = sfTexture_createFromFile("./pict/p0.png", NULL); // 1???
        batl->b_pla[i].texture = tmp;
        batl->b_pla[i].sprite = sfSprite_create();
        sfSprite_setTexture(batl->b_pla[i].sprite, tmp, sfTrue);
        batl->b_pla[i].pos = posing(50, 350, batl->b_pla[i].pos);
        sfSprite_setPosition(batl->b_pla[i].sprite, batl->b_pla[i].pos);
//-
        batl->b_pla[i].atq = 1;
        batl->b_pla[i].exp = 0;
        batl->b_pla[i].lv = 1;
        batl->b_pla[i].pv = 20;
//-
        batl->b_pla[i].rect = set_rect(rect(i, re), batl->b_pla[i].rect);
        sfSprite_setTextureRect(batl->b_pla[i].sprite, batl->b_pla[i].rect);
        sfSprite_setScale(batl->b_pla[i].sprite, (sfVector2f){2.5, 2.5});
    }
    return batl;
}

btl_t *b_enem_init(btl_t *batl, int nb)
{
    int i = 0;
    sfTexture* tmp;

    batl->b_ene = malloc(nb * sizeof(b_enem_t));
    for (; i < nb; i++) {
        batl->b_ene[i].nb = nb;
        tmp = sfTexture_createFromFile("./pict/P1.png", NULL); // ???
        batl->b_ene[i].texture = tmp;
        batl->b_ene[i].sprite = sfSprite_create();
        sfSprite_setTexture(batl->b_ene[i].sprite, tmp, sfTrue);
        batl->b_ene[i].pos = posing(160, 600, batl->b_ene[i].pos);
        sfSprite_setPosition(batl->b_ene[i].sprite, batl->b_ene[i].pos);
        batl->b_ene[i].atq = 1;
        batl->b_ene[i].pv = 15; // entre 15 et 20.
//        batl->b_pla[i].rect
        sfTexture_destroy(tmp);
    }
    return batl;
}

btl_t *b_base_txt_init(btl_t *batl, int id)
{
    int i = 0;
    int x = 175;
    int y = 590;
    void *tmp = NULL;

    batl->base = txt_mallocer();
    for (; i < 8; i++) {
        batl->base->id = id;
        batl->base->opt = i;
        batl->base->pos = (sfVector2f){x , (y + (35 * i))};
        sfText_setString(batl->base->text, menu_txt(id, i));
        tmp = batl->base;
        batl->base->next = txt_mallocer();
        if (batl->base->next == NULL)
            return po_error_disp(2);
        batl->base = batl->base->next;
        batl->base->previews = tmp;
    }
    return b_base_txt_init_2(batl);
}