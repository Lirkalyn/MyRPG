/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** main of rpg
*/

#include "rpg.h"

int main(int ac, char **av)
{
    if (ac == 2 && find_the_word(av[1], "-h"));
        //help_menu();
    if (ac == 1)
        return (main_game());
    return 84;
}