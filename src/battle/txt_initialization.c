/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** to initializa the text-desu
*/

#include "rpg.h"

txt_t *txt_mallocer(void)
{
    txt_t *tmp = malloc(sizeof(txt_t));

    tmp->id = 0;
    tmp->next = NULL;
    tmp->previews = NULL;
    tmp->opt = 0;
    tmp->pos.x = 0;
    tmp->pos.y = 0;
    tmp->text = sfText_create();
    return tmp;
}

btl_t *b_base_txt_init_2(btl_t *batl)
{
    sfFont *test = sfFont_createFromFile("rsc/Calibri Regular.ttf");

    while (batl->base->previews != NULL)
        batl->base = batl->base->previews;
    while (batl->base->next != NULL) {
        sfText_setFont(batl->base->text, test);
        sfText_setCharacterSize(batl->base->text, 40);
        sfText_setColor(batl->base->text, sfBlack);
        sfText_setPosition(batl->base->text, batl->base->pos);
        batl->base = batl->base->next;
    }
    while (batl->base->previews != NULL)
        batl->base = batl->base->previews;
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

btl_t *b_comp_txt_init(btl_t *batl, int id)
{
    int i = 0;
    int x = 175;
    int y = 590;
    void *tmp = NULL;

    batl->comp = txt_mallocer();
    for (; i < 6; i++) {
        batl->comp->id = id;
        batl->comp->opt = i;
        batl->comp->pos = (sfVector2f){x , (y + (50 * i))};
        sfText_setString(batl->comp->text, menu_txt(id, i));
        tmp = batl->comp;
        batl->comp->next = txt_mallocer();
        if (batl->comp->next == NULL)
            return po_error_disp(2);
        batl->comp = batl->comp->next;
        batl->comp->previews = tmp;
    }
    return b_comp_txt_init_2(batl);
}