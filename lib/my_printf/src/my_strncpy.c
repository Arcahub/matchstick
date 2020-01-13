/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** copy n character to string
*/

static void add_chara(char *dest, int i, int n) {
    for (int j = i; j < n; j++) {
        dest[j] = '\0';
    }
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++) {
        if (src[i] == '\0') {
            add_chara(dest, i, n);
            return (dest);
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}