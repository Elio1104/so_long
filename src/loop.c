/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:05:31 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 12:26:09 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_up(t_game *game)
{
	game->deplacement += GAME_SPEED;
	ft_window_file(game);
	if (game->deplacement < 32)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) - game->deplacement,
			game->u2);
	if (game->deplacement == 32)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) - game->deplacement,
			game->u1);
	if (game->deplacement > 32 && game->deplacement < 64)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) - game->deplacement,
			game->u3);
	if (game->deplacement >= 64)
	{
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) - game->deplacement,
			game->u1);
		ft_move_up(game);
		ft_printf("Movements: %d\n", game->pl_mov);
		game->dir = NO_DIR;
		game->deplacement = 0;
	}
}

void	animation_down(t_game *game)
{
	game->deplacement += GAME_SPEED;
	ft_window_file(game);
	if (game->deplacement < 32)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) + game->deplacement,
			game->d2);
	if (game->deplacement == 32)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) + game->deplacement,
			game->d1);
	if (game->deplacement > 32 && game->deplacement < 64)
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) + game->deplacement,
			game->d3);
	if (game->deplacement >= 64)
	{
		ft_put_player(game, game->pxl * game->pl_x,
			(game->pxl * game->pl_y) + game->deplacement,
			game->d1);
		ft_move_down(game);
		ft_printf("Movements: %d\n", game->pl_mov);
		game->dir = NO_DIR;
		game->deplacement = 0;
	}
}

void	animation_left(t_game *game)
{
	game->deplacement += GAME_SPEED;
	ft_window_file(game);
	if (game->deplacement < 32)
		ft_put_player(game, game->pxl * game->pl_x - game->deplacement,
			game->pxl * game->pl_y, game->l2);
	if (game->deplacement == 32)
		ft_put_player(game, game->pxl * game->pl_x - game->deplacement,
			game->pxl * game->pl_y, game->l1);
	if (game->deplacement > 32 && game->deplacement < 64)
		ft_put_player(game, game->pxl * game->pl_x - game->deplacement,
			game->pxl * game->pl_y, game->l3);
	if (game->deplacement >= 64)
	{
		ft_put_player(game, game->pxl * game->pl_x - game->deplacement,
			game->pxl * game->pl_y, game->l1);
		ft_move_left(game);
		ft_printf("Movements: %d\n", game->pl_mov);
		game->dir = NO_DIR;
		game->deplacement = 0;
	}
}

void	animation_right(t_game *game)
{
	game->deplacement += GAME_SPEED;
	ft_window_file(game);
	if (game->deplacement < 32)
		ft_put_player(game, game->pxl * game->pl_x + game->deplacement,
			game->pxl * game->pl_y, game->r2);
	if (game->deplacement == 32)
		ft_put_player(game, game->pxl * game->pl_x + game->deplacement,
			game->pxl * game->pl_y, game->r1);
	if (game->deplacement > 32 && game->deplacement < 64)
		ft_put_player(game, game->pxl * game->pl_x + game->deplacement,
			game->pxl * game->pl_y, game->r3);
	if (game->deplacement >= 64)
	{
		ft_put_player(game, game->pxl * game->pl_x + game->deplacement,
			game->pxl * game->pl_y, game->r1);
		ft_move_right(game);
		ft_printf("Movements: %d\n", game->pl_mov);
		game->dir = NO_DIR;
		game->deplacement = 0;
	}
}

int	main_loop(t_game *game)
{
	if (game->dir == UP)
		animation_up(game);
	if (game->dir == LEFT)
		animation_left(game);
	if (game->dir == DOWN)
		animation_down(game);
	if (game->dir == RIGHT)
		animation_right(game);
	return (0);
}
