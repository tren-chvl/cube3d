/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcheva <marcheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:08:22 by marcheva          #+#    #+#             */
/*   Updated: 2026/02/03 16:21:38 by marcheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(t_map *map)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			tmp = map->map[i][j];
			if (tmp != '0' && tmp != '1' && tmp != 'N' && tmp != 'S'
				&& tmp != 'E' && tmp != 'W')
			{
				printf("Error\nInvalid character in map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				if (!init_player(map, i, j))
					return (0);
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		printf("Errror\nInvalid number of player\n");
		return (0);
	}
	return (1);
}

int	check_closed(t_map *map)
{
	char	**dup;
	int		h;
	int		w;
	int		i;
	int		j;

	i = 0;
	dup = dup_map(map, &h, &w);
	if (!dup)
		return (0);
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (dup[i][j] == '0' || dup[i][j] == 'N'
				|| dup[i][j] == 'S' || dup[i][j] == 'E'
				|| dup[i][j] == 'W')
			{
				if (!flood(dup, i, j, h, w))
				{
					free_dup(dup);
					printf("Error\nMap is not closed\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	free_dup(dup);
	return (1);
}
