/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MY_H_
#define MY_H_

#define EXIT_FAIL 84

typedef struct window_s
{
    sfRenderWindow* window;
    sfEvent event;
}window_t;

typedef struct background_s
{
    sfTexture* texture;
    sfSprite* sprite;
}background_t;

int find_the_word(char *str, char *find);
int main_game();

#endif /* !MY_H_ */