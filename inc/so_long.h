/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:08:25 by alondot           #+#    #+#             */
/*   Updated: 2022/08/19 16:08:34 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/inc/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game {
	void    mlx;        //mlx init
	void    mlx_win;    //mlx win init
    char	*file;      //img conv
    char    **map;      //tab map [y][x]
    int     map_area;   //x * y
    int     map_x;      //x size
    int     map_y;      //y size
    int     pxl;        //pixel img
    int     player_x;   //player pos x
    int     player_y;   //player pos y
    int     player_mov; //count player moves
    char    *pl_dir;    //tileset player
    int     collect;    //count collect
    int     player;     //count player
    int     exit;       //count exit
}   t_game;

# define TRUE 1
# define FALSE 0

#endif 
