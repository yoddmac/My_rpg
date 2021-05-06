/*
** EPITECH PROJECT, 2019
** str_to_word_tab
** File description:
** str_to_word_tab
*/

int my_getnbr(char const *str)
{
    int resultat = 0;
    int signe = 1;

    while (('-' == (*str)) || ((*str) == '+')) {
        if (*str == '-') {
            signe = signe * -1;
        }
        str++;
    }
    while ((*str >= '0') && (*str <= '9')) {
        resultat = (resultat * 10) + ((*str) - '0');
        str++;
    }
    return (resultat * signe);
}