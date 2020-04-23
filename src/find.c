/*
** EPITECH PROJECT, 2020
** find.c
** File description:
** find.c
*/

int find_the_word(char *str, char *find)
{
    int i = 0;

    for (i = 0; str[i] == find[i] && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return (1);
    return (0);
}

int fine_at_the_end(char *str, char *find)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (x = 0; str[i] == find[x] && find[x] != '\0'; i++, x++);
        if (str[i] == '\0' && find[x] == '\0')
            i--;
    }
    if (find[x] == '\0')
        return (1);
    return (0);
}