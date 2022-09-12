/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:58:32 by alondot           #+#    #+#             */
/*   Updated: 2022/09/12 10:51:04 by alondot          ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	char	*file;
	char	**map;
	int		map_area;
	int		map_x;
	int		map_y;
	int		pxl;
	int		pl_x;
	int		pl_y;
	int		x;
	int		y;
	int		pl_mov;
	char	*pl_dir;
	int		collect;
	int		player;
	int		exit;
	int		dir;
	int		deplacement;
	char	*u1;
	char	*u2;
	char	*u3;
	char	*d1;
	char	*d2;
	char	*d3;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*r1;
	char	*r2;
	char	*r3;
	char	*v;
	char	*e;
	char	*c;
	char	*g;
	char	*t;
}	t_game;

# define GAME_SPEED 4

# define NO_DIR 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

void	ft_borders_error(void);
void	ft_check_x_border(t_game *game);
void	ft_check_y_border(t_game *game);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_keyboard(int keyhook, t_game *game);

void	ft_check_map(char *buffer, t_game *game);
void	ft_check_pce(char *buffer, t_game *game);
char	*ft_join(char *line, char c);
int		t_check(char *line);
char	*get_map(int fd, t_game *game);

void	ft_window(t_game *game);
void	checking_map(char **argv, t_game *game);
void	ft_init_struct(t_game *game);
void	checking_arg(int argc, char **argv);

int		ft_close_window(t_game *game);
void	draw_step_count(t_game *game);
void	ft_put_exit(t_game *game);
void	ft_put_player(t_game *game, int x, int y, char *str);
void	ft_put_collect(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_wall(t_game *game);
void	ft_fill_floor(t_game *game);
void	ft_window_file(t_game *game);

int		check_ce(char **tmp, t_game *game);
int		backtracking(char **tab, int x, int y, t_game *game);
int		path_checking(t_game game);
void	pl_xy(t_game *game);

void	animation_up(t_game *game);
int		main_loop(t_game *game);
void	check_vilain(int keyhook, t_game *game);
void	ft_put_vilain(t_game *game);

#endif 
