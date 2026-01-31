#include "cub3d.h"

int init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)  
	{
		printf("Error\nMLX init failed\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, 800, 600, "cub3d");
	if (!game->win)
	{
		printf("Error\nMLX init failed\n");
		return (0);
	}
	return (1);
}

void init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->tex_no = NULL;
	game->tex_so = NULL;
	game->tex_we = NULL;
	game->tex_ea = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0;
}
