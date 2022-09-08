/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:02:24 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 13:05:54 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_floor(t_game *game)
{
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->g, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_fill_floor(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			ft_put_floor(game);
			game->x++;
		}
		game->y++;
	}
}
