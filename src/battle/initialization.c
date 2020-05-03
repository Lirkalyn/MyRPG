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

btl_t *f_init(window_t *w, player_t **p, btl_t *batl)
{
    batl->phase = 0;
    batl->p = p;
    batl->w = w;
    batl->bck.texture = sfTexture_createFromFile("./pict/batl_bck2.jpg", NULL);
    batl->bck.sprite = sfSprite_create();
    sfSprite_setTexture(batl->bck.sprite, batl->bck.texture, sfTrue);
    return batl;
}

btl_t *batl_init(window_t *w, player_t **p)
{
    btl_t *batl = malloc(sizeof(btl_t));
    sfVector2f pos = posing(0, 0, pos);
    srand(rand());

    if (batl == NULL)
        return NULL;
    batl = f_init(w, p, batl);
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