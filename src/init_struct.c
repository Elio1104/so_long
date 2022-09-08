/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:39:10 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 16:38:24 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_img_to_xpm(t_game *game, char *str)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			str, &game->pxl, &game->pxl);
	return (game->file);
}

void	ft_init_img(t_game *game)
{
	game->u1 = ft_img_to_xpm(game, "./img/player/Dawn_up1.xpm");
	game->u2 = ft_img_to_xpm(game, "./img/player/Dawn_up2.xpm");
	game->u3 = ft_img_to_xpm(game, "./img/player/Dawn_up3.xpm");
	game->d1 = ft_img_to_xpm(game, "./img/player/Dawn_down1.xpm");
	game->d2 = ft_img_to_xpm(game, "./img/player/Dawn_down2.xpm");
	game->d3 = ft_img_to_xpm(game, "./img/player/Dawn_down3.xpm");
	game->r1 = ft_img_to_xpm(game, "./img/player/Dawn_right1.xpm");
	game->r2 = ft_img_to_xpm(game, "./img/player/Dawn_right2.xpm");
	game->r3 = ft_img_to_xpm(game, "./img/player/Dawn_right3.xpm");
	game->l1 = ft_img_to_xpm(game, "./img/player/Dawn_left1.xpm");
	game->l2 = ft_img_to_xpm(game, "./img/player/Dawn_left2.xpm");
	game->l3 = ft_img_to_xpm(game, "./img/player/Dawn_left3.xpm");
	game->e = ft_img_to_xpm(game, "./img/exit.xpm");
	game->c = ft_img_to_xpm(game, "./img/pokeball.xpm");
	game->v = ft_img_to_xpm(game, "./img/vilain.xpm");
	game->t = ft_img_to_xpm(game, "./img/Tree.xpm");
	game->g = ft_img_to_xpm(game, "./img/Grass.xpm");
}

void	ft_init_struct(t_game *game)
{
	game->map_area = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->pl_x = 0;
	game->pl_y = 0;
	game->x = 0;
	game->y = 0;
	game->player = 0;
	game->pl_mov = 0;
	game->collect = 0;
	game->exit = 0;
	game->dir = NO_DIR;
	game->deplacement = 0;
	game->pxl = 64;
	game->mlx = mlx_init();
	ft_init_img(game);
	game->file = game->d1;
}
