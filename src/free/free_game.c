#include "cub3d.h"

void free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->tex_no)
		free(game->tex_no);
	if (game->tex_so)
		free(game->tex_so);
	if (game->tex_we)
		free(game->tex_we);
	if (game->tex_ea)
		free(game->tex_ea);
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
