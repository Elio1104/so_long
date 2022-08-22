#include <so_long.h>

void checking_pce()
{

}

void get_map(int fd, t_game *game)
{
    while (1)
    {
        if (!buffer = get_next_line(fd))
            break;
        line = ft_strjoin(line, buffer);
    }
    game->map = ft_split(line, '\n');
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
    get_map(fd, &game);
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
    checking_map(argv, &game);
    return (0);
}