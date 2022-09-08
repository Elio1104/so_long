/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:58:32 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 16:35:35 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

void	check_vilain(int keyhook, t_game *game)
{
	int	x;

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

void	draw_step_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->pl_mov);
	mlx_string_put(game->mlx, game->mlx_win, 25, 30, 0xffffff, str);
	free(str);
}

void	ft_put_vilain(t_game *game)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->v, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_player(t_game *game, int x, int y, char *img)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		img, x, y);
}
