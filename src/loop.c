#include "so_long.h"

void    animation_up(t_game *game)
{
    game->deplacement += 8;
    ft_window_file(game);
    if(game->deplacement < 32)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) - game->deplacement, "./img/player/Dawn_up2.xpm");
    if(game->deplacement == 32)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) - game->deplacement, "./img/player/Dawn_up1.xpm");
    if(game->deplacement > 32 && game->deplacement < 64)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) - game->deplacement, "./img/player/Dawn_up3.xpm");
    if(game->deplacement >= 64)
    {
        mlx_clear_window(game->mlx, game->mlx_win);
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) - game->deplacement, "./img/player/Dawn_up1.xpm");
        ft_move_up(game);
	    ft_printf("Movements: %d\n", game->pl_mov);
        game->dir = NO_DIR;
        game->deplacement = 0;
    }
}
void    animation_down(t_game *game)
{
    game->deplacement += 8;
    ft_window_file(game);
    if(game->deplacement < 32)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) + game->deplacement, "./img/player/Dawn_down2.xpm");
    if(game->deplacement == 32)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) + game->deplacement, "./img/player/Dawn_down1.xpm");
    if(game->deplacement > 32 && game->deplacement < 64)
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) + game->deplacement, "./img/player/Dawn_down3.xpm");
    if(game->deplacement >= 64)
    {
        ft_put_player(game, game->pxl * game->pl_x, (game->pxl * game->pl_y) + game->deplacement, "./img/player/Dawn_down1.xpm");
        ft_move_down(game);
	    ft_printf("Movements: %d\n", game->pl_mov);
        game->dir = NO_DIR;
        game->deplacement = 0;
    }
}
void    animation_left(t_game *game)
{
    game->deplacement += 8;
    ft_window_file(game);
    if(game->deplacement < 32)
        ft_put_player(game, game->pxl * game->pl_x  - game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_left2.xpm");
    if(game->deplacement == 32)
        ft_put_player(game, game->pxl * game->pl_x  - game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_left1.xpm");
    if(game->deplacement > 32 && game->deplacement < 64)
        ft_put_player(game, game->pxl * game->pl_x  - game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_left3.xpm");
    if(game->deplacement >= 64)
    {
        ft_put_player(game, game->pxl * game->pl_x  - game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_left1.xpm");
        ft_move_left(game);
	    ft_printf("Movements: %d\n", game->pl_mov);
        game->dir = NO_DIR;
        game->deplacement = 0;
    }
}

void    animation_right(t_game *game)
{
    game->deplacement += 8;
    ft_window_file(game);
    if(game->deplacement < 32)
        ft_put_player(game, game->pxl * game->pl_x  + game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_right2.xpm");
    if(game->deplacement == 32)
        ft_put_player(game, game->pxl * game->pl_x  + game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_right1.xpm");
    if(game->deplacement > 32 && game->deplacement < 64)
        ft_put_player(game, game->pxl * game->pl_x  + game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_right3.xpm");
    if(game->deplacement >= 64)
    {
        ft_put_player(game, game->pxl * game->pl_x  + game->deplacement, game->pxl * game->pl_y, "./img/player/Dawn_right1.xpm");
        ft_move_right(game);
	    ft_printf("Movements: %d\n", game->pl_mov);
        game->dir = NO_DIR;
        game->deplacement = 0;
    }
}

int     main_loop(t_game *game)
{
    if (game->dir == UP)
        animation_up(game);
    if (game->dir == LEFT)
        animation_left(game);
    if (game->dir == DOWN)
        animation_down(game);
    if (game->dir == RIGHT)
        animation_right(game);
    return(0);
}