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
			if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
                return(1);
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
    if (tmp [y][x] == 'C' || tmp [y][x] == 'E')
        game->map[y][x] = 1;
    tmp[y][x] = 2;
    if(!check_ce(game->map, game))
        return (1);
    if(check_ce(game->map, game) && (tmp[y][x - 1] == '0' || tmp[y][x - 1] == 'C' || tmp[y][x - 1] == 'E'))//gauche
        z = backtracking(tmp, x - 1, y, game);
    if(check_ce(game->map, game) && (tmp[y - 1][x] == '0' || tmp[y - 1][x] == 'C' || tmp[y - 1][x] == 'E'))//haut
        z = backtracking(tmp, x, y - 1, game);
    if(check_ce(game->map, game) && (tmp[y + 1][x] == '0' || tmp[y + 1][x] == 'C' || tmp[y + 1][x] == 'E'))//bas
        z = backtracking(tmp, x, y + 1, game);
    if(check_ce(game->map, game) && (tmp[y][x + 1] == '0' || tmp[y][x + 1] == 'C' || tmp[y][x + 1] == 'E'))//droite
        z = backtracking(tmp, x + 1, y, game);
    if(!check_ce(game->map, game))
        return (1);
    return (0);
}

void pl_xy(t_game *game)
{
    int x;
    int y;

    y = 0;
	while (y < (game->map_y))
	{
		x = 0;
		while (x < (game->map_x))
		{
			if (game->map[y][x] == 'P')
            {
                game->pl_y = y;
                game->pl_x = x;
            }
			x++;
		}
		y++;
	}
}

int path_checking(t_game game)
{
    char **tmp;

    tmp = game.map;
    pl_xy(&game);
    if (backtracking(tmp, game.pl_x, game.pl_y, &game))
    {
        return (1);
    }
    game.map = tmp;
    ft_printf("Error\nGame can't be finish\n");
    exit(0);
    return (0);
}