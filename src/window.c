/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:02:24 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 13:05:54 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_exit(t_game *game)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->e, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_collect(t_game *game)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->c, game->pxl * game->x,
		game->pxl * game->y);
	game->collect++;
}

void	ft_put_wall(t_game *game)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->t, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_window_file(t_game *game)
{
	ft_fill_floor(game);
	game->y = 0;
	game->collect = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == '1')
				ft_put_wall(game);
			if (game->map[game->y][game->x] == 'V')
				ft_put_vilain(game);
			if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	draw_step_count(game);
}
