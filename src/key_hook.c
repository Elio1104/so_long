#include "so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y - 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/player/Dawn_up1.xpm";
	ft_window_file(game);
}

void	ft_move_down(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y + 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/player/Dawn_down1.xpm";
	ft_window_file(game);
}

void	ft_move_left(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x - 1] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/player/Dawn_left1.xpm";
	ft_window_file(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x + 1] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/player/Dawn_right1.xpm";
	ft_window_file(game);
}
void check_vilain(int keyhook, t_game *game)
{
	int x;

	x = 0;
	if (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'V')
		x = 1;
	if (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'V')
		x = 1;
	if (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'V')
		x = 1;
	if (keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'V')
		x = 1;
	if (x)
	{
		ft_printf("GAME OVER");
		exit(0);
	}
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		ft_close_window(game);
	if (game->collect == 0
		&& ((keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'E')
		|| (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'E')
		|| (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'E')
		|| (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'E')))
	{
		ft_printf("OAK: Oh! Thank you for collecting all my Pokemon!\n");
		ft_close_window(game);
	}
	check_vilain(keyhook, game);
	if (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] != '1'
		&& game->map[game->pl_y - 1][game->pl_x] != 'E')
		ft_move_up(game);
	if (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] != '1'
		&& game->map[game->pl_y][game->pl_x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] != '1'
		&& game->map[game->pl_y + 1][game->pl_x] != 'E')
		ft_move_down(game);
	if (keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] != '1'
		&& game->map[game->pl_y][game->pl_x + 1] != 'E')
		ft_move_right(game);
	return (0);
}