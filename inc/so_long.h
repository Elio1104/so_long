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

# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game {
	void    *mlx;        //mlx init
	void    *mlx_win;    //mlx win init
    char	*file;      //img conv
    char    **map;      //tab map [y][x]
    int     map_area;   //x * y
    int     map_x;      //x size
    int     map_y;      //y size
    int     pxl;        //pixel img
    int     pl_x;   //player pos x
    int     pl_y;   //player pos y
    int     x;
    int     y;
    int     pl_mov; //count player moves
    char    *pl_dir;    //tileset player
    int     collect;    //count collect
    int     player;     //count player
    int     exit;       //count exit
}   t_game;

# define TRUE 1
# define FALSE 0

void	ft_borders_error(void);
void	ft_check_x_border(t_game *game);
void	ft_check_y_border(t_game *game);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int     ft_keyboard(int keyhook, t_game *game);

void	ft_check_map(char *buffer, t_game *game);
void	ft_check_pce(char *buffer, t_game *game);
char	*ft_join(char *line, char c);
int	    t_check(char *line);
char    *get_map(int fd, t_game *game);

void	ft_window(t_game *game);
void    checking_map(char **argv, t_game *game);
void	ft_init_struct(t_game *game);
void    checking_arg(int argc, char **argv);

void	ft_close_window(t_game *game);
void    ft_put_exit(t_game *game);
void    ft_put_player(t_game *game);
void    ft_put_collect(t_game *game);
void    ft_put_floor(t_game *game);
void    ft_put_wall(t_game *game);
void	ft_fill_floor(t_game *game);
void	ft_window_file(t_game *game);

int     check_ce(char **tmp, t_game *game);
int     backtracking(char **tab, int x, int y, t_game *game);
int     path_checking(t_game game);
void    pl_xy(t_game *game);

#endif 
