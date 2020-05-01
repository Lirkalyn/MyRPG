/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** lurk moar-desu
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

char *b_copy(char *str)
{
    int i = 0;
    int len = 0;
    char *tmp = NULL;

    for (; str[len] != '\0'; len++);
    tmp = malloc((len + 1) * sizeof(char));
    if (tmp == NULL)
        return po_error_disp(1);
    tmp[len] = '\0';
    for (; str[i] != '\0'; i++)
        tmp[i] = str[i];
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

char *menu_txt(int id, int pos)
{
    char *tmp = NULL;
    char base[8][8] = {"Attack\0", "Defense\0", "Skill\0", "Bravely\0",
                        "Default\0", "Inspect\0", "Run\0", 0};
    char comp[5][8] = {"Attack\0", "Defense\0", "Skill\0", "Bravely\0", 0};

    if (id == 0 && pos < 8)
        return b_copy(base[pos]);
    else if (id == 1 && pos < 5)
        return b_copy(comp[pos]);
    else
        return po_error_disp(3);
}