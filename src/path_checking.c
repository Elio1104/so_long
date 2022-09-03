#include "so_long.h"

int check_ce(char **tmp, t_game *game)
{
    int x;
    int y;

    y = 0;
	while (y < (game->map_y))
	{
		x = 0;
		while (x < (game->map_x))
		{
			if (tmp[y][x] == 'C' || 'E')
			x++;
		}
		y++;
	}
    return (0);
}

int backtracking(char **tab, int x, int y, t_game *game)
{
    int z;
    char **tmp;

    tmp = tab;
    if (tmp [y][x] == 'C' || 'E')
        game->map[y][x] = 5;
    tmp[y][x] = 2;
    if(!check_ce(&game->map, game))
        return (1);
    if(check_ce(tmp) && tmp[y][x - 1] == 0 || 'C' || 'E')//gauche
        z = backtracking(tmp, x - 1, y, &game);
    else if(check_ce(tmp) && tmp[y - 1][x] == 0 || 'C' || 'E')//haut
        z = backtracking(tmp, x, y - 1, &game);
    else if(check_ce(tmp) && tmp[y + 1][x] == 0 || 'C' || 'E')//bas
        z = backtracking(tmp, x, y + 1, &game);
    else if(check_ce(tmp) && tmp[y][x + 1] == 0 || 'C' || 'E')//droite
        z = backtracking(tmp, x + 1, y, &game);
    if(!check_ce(&game->map, game))
        return (1);
    return (0);
}

int path_checking(t_game game)
{
    char **tmp;

    tmp = game->map;
    if (backtracking(tmp, game->pl_x, game->pl_y, &game))
    {
        return (1);
    }
    ft_printf("Error : Game can't be finish\n");
    exit;
    return (0);
}