/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** more function to initialize the text-desu
*/

#include "rpg.h"

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

char *menu_txt(int id, int pos)
{
    char *tmp = NULL;
    char base[8][8] = {"Attack\0", "Defense\0", "Skill\0", "Bravely\0",
                        "Default\0", "Inspect\0", "Run\0", 0};
    char comp[6][10] = {"Punch\0", "Axe swing\0", "Slash\0", "Tornado\0",
                        "<-- Back\0", 0};

    if (id == 0 && pos < 8)
        return b_copy(base[pos]);
    else if (id == 1 && pos < 6)
        return b_copy(comp[pos]);
    else
        return po_error_disp(3);
}