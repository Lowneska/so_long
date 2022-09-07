#include "../include/so_long.h"

int check_path(char **tab, int i, int j)
{
    if (tab[i + 1][j] && tab[i + 1][j] != '1')
        return check_path(tab, i + 1, j);
    if (tab[i - 1][j] && tab[i - 1][j] != '1')
        return check_path(tab, i - 1, j);
    if (tab[i][j + 1] && tab[i][j + 1] != '1')
        return check_path(tab, i, j + 1);
    if (tab[i][j - 1] && tab[i][j - 1] != '1')
        return check_path(tab, i, j - 1);
    if (tab[i][j] && tab[i][j] == 'E')
        return (1);
    else
        return (0);
}