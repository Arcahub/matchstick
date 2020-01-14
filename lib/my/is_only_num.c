/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** is_only_num
*/

int is_only_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}