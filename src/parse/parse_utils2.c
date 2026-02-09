/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:31:43 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/05 15:40:00 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_map *map, int i, int j)
{
	map->player_x = i;
	map->player_y = j;
	map->dir = map->map[i][j];
	map->map[i][j] = '0';
	return (1);
}

int	all_elements_parsed(t_map *map)
{
	return (map->north && map->south && map->east && map->west);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
