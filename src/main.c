/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:45:01 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:18:32 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_map *map)
{
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceiling[0] = -1;
	map->ceiling[1] = -1;
	map->ceiling[2] = -1;
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->map = NULL;
	map->player_x = -1;
	map->player_y = -1;
	map->dir = 0;
	map->first_line = NULL;
}

// int	main(int argc, char *argv[])
// {
// 	t_game	game;
// 	t_map	map;

// 	if (argc != 2)
// 	{
// 		printf("Error\nInvalid number of argument\n");
// 		return (1);
// 	}
// 	if (!parse_cub(&map, argv[1]))
// 	{
// 		free_map(&map);
// 		return (1);
// 	}
// 	// if (!init_mlx(&map))
// 	// {
// 	// 	free_game(&map);
// 	// 	return (1);
// 	// }
// 	mlx_loop(game.mlx);
// 	free_map(&map);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (printf("Error\nInvalid number of argument\n"), 1);
	if (!parse_cub(&map, av[1]))
		return (1);
	printf("PARSING OK\n");
	return (0);
}
