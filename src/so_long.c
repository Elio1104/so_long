/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alondot <alondot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:55:40 by alondot           #+#    #+#             */
/*   Updated: 2022/09/08 13:00:57 by alondot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "So_long : Version Pokemon");
	ft_window_file(game);
	ft_printf("Movements: %d\n", game->pl_mov);
	pl_xy(game);
	ft_put_player(game, game->pxl * game->pl_x,
		game->pxl * game->pl_y, game->file);
}

void	checking_map(char **argv, t_game *game)
{
	char	*buffer;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error!\nThe map could not be read.\n");
		exit (1);
	}
	buffer = get_map(fd, game);
	ft_check_pce(buffer, game);
	game->map = ft_split(buffer, '\n');
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
	ft_check_map(buffer, game);
	close(fd);
}

void	checking_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error/nInvalid number of arguments. Must be 2.");
		exit (0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf("Error\nInvalid file type. Must be: \"<name>.ber\"\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_game	tmp;

	checking_arg(argc, argv);
	ft_init_struct(&tmp);
	checking_map(argv, &tmp);
	ft_init_struct(&game);
	checking_map(argv, &game);
	path_checking(tmp);
	ft_window(&game);
	mlx_key_hook(game.mlx_win, ft_keyboard, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
