/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:58:32 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 11:59:15 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_border_error(void)
{
	ft_printf("Error!\nNot enough wall in the screen limits.\n");
	exit(1);
}

void	ft_check_x_border(t_game *game)
{
	while ((game->x) < (game->map_x))
	{
		if (game->map[0][game->x] != '1')
			ft_border_error();
		game->x++;
	}
	game->y = game->map_y - 1;
	game->x = 0;
	while ((game->x) < (game->map_x))
	{
		if (game->map[game->y][game->x] != '1')
			ft_border_error();
		game->x++;
	}
}

void	ft_check_y_border(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][0] != '1')
			ft_border_error();
		game->y++;
	}
	game->y = 0;
	game->x = game->map_x - 1;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][game->x] != '1')
			ft_border_error();
		game->y++;
	}
}
