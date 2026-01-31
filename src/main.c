#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_game  game;

	if (argc != 2)
		return (printf("Error\nInvalid number of arguments\n"), 1);
	if (!parse_cub(&game, argv[1]))
		return (free_game(&game), 1);
	if (!init_mlx(&game))
		return (free_game(&game), 1);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
