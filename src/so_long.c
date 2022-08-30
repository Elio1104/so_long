#include "so_long.h"

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "So_long : Aaron Londot");
    
}

void checking_map(char **argv, t_game *game)
{
    char *buffer;
    char *line;
    int fd;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		ft_printf("Error!\nThe map could not be read.\n");
		exit (1);
	}
    buffer = get_map(fd, &game);
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

void	ft_init_struct(t_game *game)
{
    game->map_area = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->x = 0;
	game->y = 0;
	game->player = 0;
	game->player_mov = 0;
	game->player_dir = "!!!!!!!!!!!!";
	game->collect = 0;
	game->exit = 0;
}

void checking_arg(int argc, char **argv)
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

int main(int argc, char **argv)
{
    t_game game;

    checking_arg(argc, argv);
    ft_init_struct(&game);
    checking_map(argv, &game);
    return (0);
}